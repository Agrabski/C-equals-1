#include "BuiltInPackageBuildUtility.hpp"
#include <boost/algorithm/string/replace.hpp>
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "LiteralUtility.hpp"
#include "CompileTimeFunctions/FunctionLibrary.hpp"
#include "CompileTimeFunctions/Print.hpp"
#include "CompileTimeFunctions/ReplaceWithCompilerFunction.hpp"
#include "CompileTimeFunctions/ReplaceWithExternalSymbol.hpp"
#include "CompileTimeFunctions/RaiseError.hpp"
#include "CompileTimeFunctions/ReplaceWithCompilerType.hpp"
#include "CompileTimeFunctions/MarkCompileTimeOnly.hpp"
#include "IRUtility.hpp"
#include "MetatypeUility.hpp"
#include "InstantiateGeneric.hpp"
#include "CreateGetter.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "CompileTimeFunctions/ReadAllFile.hpp"
#include "LLVMBindings/LLVMBindings.hpp"
#include "../DataStructures/execution/RuntimePackageDescriptor.hpp"
#include "SpecialFunctionUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "GenericUtility.hpp"
#include "../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "MetadataHolderBindings.hpp"
#include "TypeCoercionUtility.hpp"
#include "Libraries/Libraries.hpp"

using namespace cMCompiler::dataStructures::execution;

using namespace std::string_literals;
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;
auto const compiler_namespace__ = "compiler";
auto const compile_time_type_descriptor__ = "typeDescriptor";
auto const compile_time_function_descriptor__ = "functionDescriptor";

static auto defaultPackage__ = std::make_unique<PackageDatabase>("cm1mLang");

void appendCasts(not_null<Namespace*> rootNs)
{
	using cMCompiler::dataStructures::execution::ReferenceValue;
	gsl::not_null<Generic<Function>*> g = rootNs->appendGeneric<Function>(
		{ "T", "Y" },
		[rootNs, g](auto const& params) -> not_null<Function*>
		{
			auto result = rootNs->append<Function>(getGenericMangledName("cast", params));

			auto returnType = params[0];
			result->appendVariable("a", params[1].reference());
			result->setReturnType(returnType.reference());
			cMCompiler::language::compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(
				result,
				[returnType](auto&& a, auto) -> runtime_value
				{
					auto param = a["a"]->copy();
					auto ref = dynamic_cast<ReferenceValue*>(param.get());
					auto val = dereferenceOnce(param.get());
					if (coerce(val->type().reference(), returnType.reference()))
						return ReferenceValue::make(ref->value(), returnType);
					return ReferenceValue::make(nullptr, returnType);
				}
			);
			result->setInstantiationData({ defaultPackage__->rootNamespace()->get<Generic<Function>>("cast"), params });
			result->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));

			return result;
		},
		"cast", cMCompiler::dataStructures::NameResolutionContext(getDefaultPackage()),
			"C-=-1_library_internals.cm"
			);
}


void setAllFunctionsCompileTimeOnly(not_null<INamedObject*> obj)
{
	auto f = dynamic_cast<Function*>(obj.get());
	if (f != nullptr)
	{
		f->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);
	}
	else
	{
		auto t = dynamic_cast<Type*>(obj.get());
		if (t != nullptr)
			t->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
		for (auto child : obj->children())
			setAllFunctionsCompileTimeOnly(child);
	}
}

void setSourcePointer(not_null<INamedObject*> obj)
{
	obj->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));
	auto type = dynamic_cast<Type*>(obj.get());
	if (type != nullptr && type->parent()->name() == "ir")
		type->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	for (auto child : obj->children())
		setSourcePointer(child);
}


void buildCompilerEntryPointAttribute(gsl::not_null<Namespace*> compilerNs)
{
	auto result = compilerNs->append<Attribute>("compilerEntryPoint");
	auto f = result->appendFunction("attach");
	f->appendVariable("self", { result->describingType(), 1 });
	f->appendVariable("", { getFunctionDescriptor(), 0 });
	f->setIrCollection(std::make_unique<execution::ArrayValue>(TypeReference{ getCollectionTypeFor(
			TypeReference{ getIInstruction(), 1 }), 0 },
		TypeReference{ getIInstruction() ,1 }
		)
	);
	result->addAttributeTarget(Target::Function);
}

gsl::not_null<Type*> buildTypeDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto type = compilerNs->append<Type>("typeDescriptor");
	type->setTypeClassifier(TypeClassifier::Class);
	type->setAccessibility(Accessibility::Public);
	type->appendField("name", { cMCompiler::language::getString(), 0 })->setAccessibility(Accessibility::Public);
	type->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	return type;
}

gsl::not_null<Type*> buildFunctionDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto function = compilerNs->append<Type>("functionDescriptor");
	function->setTypeClassifier(TypeClassifier::Class);
	function->setAccessibility(Accessibility::Public);
	function->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	return function;
}

gsl::not_null<Type*> buildNamespaceDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto ns = compilerNs->append<Type>("namespaceDescriptor");
	ns->setTypeClassifier(TypeClassifier::Class);
	ns->setAccessibility(Accessibility::Public);
	ns->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	return ns;
}

gsl::not_null<Type*> buildPackageDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	using cMCompiler::dataStructures::execution::RuntimePackageDescriptor;
	auto ns = compilerNs->append<Type>("packageDescriptor");
	ns->setTypeClassifier(TypeClassifier::Class);
	ns->setAccessibility(Accessibility::Public);
	ns->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);

	createCustomFunction(
		ns->append<Function>("getAllTypes")->setReturnType({ getCollectionTypeFor({ getTypeDescriptor(), 0 }), 0 }),
		ns,
		[](auto&& args, auto)
		{
			auto self = dereferenceAs<RuntimePackageDescriptor>(args["self"].get())->value();
			return convertCollection(self->getAllTypes(), { getTypeDescriptor(), 0 });
		}
	);
	createCustomFunction(
		ns->append<Function>("getAllFunctions")->setReturnType({ getCollectionTypeFor({ getFunctionDescriptor(), 0 }), 0 }),
		ns,
		[](auto&& args, auto)
		{
			auto self = dereferenceAs<RuntimePackageDescriptor>(args["self"].get())->value();
			return convertCollection(self->getAllFunctions(), { getFunctionDescriptor(), 0 });
		}
	);

	createCustomFunction(
		ns->append<Function>("name")->setReturnType({ getString(), 0 }),
		ns,
		[](auto&& args, auto)
		{
			auto self = dereferenceAs<RuntimePackageDescriptor>(args["self"].get())->value();
			return buildStringValue(self->name());
		}
	);

	createCustomFunction(
		ns->append<Function>("dependencies")->setReturnType({ getCollectionTypeFor({ ns, 0 }), 0 }),
		ns,
		[ns](auto&& args, auto)
		{
			auto self = dereferenceAs<RuntimePackageDescriptor>(args["self"].get())->value();
			std::vector<not_null<PackageDatabase*>> p;
			for (auto& pa : self->dependencies())
				p.push_back(pa.get());
			return getValueFor(std::move(p));
		}
	);

	return ns;
}

gsl::not_null<Type*> buildPointerToSource(gsl::not_null<Namespace*> compilerNs)
{
	auto t = compilerNs->append<Type>("pointerToSource");
	t->setTypeClassifier(TypeClassifier::Class);
	t->setAccessibility(Accessibility::Public);
	t->appendField("filename", { cMCompiler::language::getString(), 0 })->setAccessibility(Accessibility::Public);
	t->appendField("lineNumber", { cMCompiler::language::getUsize(), 0 })->setAccessibility(Accessibility::Public);
	t->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));

	return t;
}

void completeBuildingType(gsl::not_null<Type*> type)
{
	type->appendField("parent", { cMCompiler::language::getNamespaceDescriptor(), 1 })->setAccessibility(Accessibility::Public);
	createCustomFunction(
		type
		->append<Function>("qualifiedName")
		->setReturnType({ cMCompiler::language::getString(), 0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return buildStringValue((std::string)self.type->qualifiedName());
		}
	)->setAccessibility(Accessibility::Public);
	createCustomFunction(
		type
		->append<Function>("methods")
		->setReturnType({ getCollectionTypeFor({ cMCompiler::language::getFunctionDescriptor(), 0 }),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			auto methods = self.type->methods();
			return convertCollection(methods, { getFunctionDescriptor(), 0 });
		}
	)->setAccessibility(Accessibility::Public);
	createNativeObjectGetter<TypeReference>(
		"fields",
		type,
		{ getCollectionTypeFor({getFieldDescriptor(), 0}), 0 },
		[](TypeReference* t)
		{
			return convertCollection(t->type->fields(), { getFieldDescriptor(), 0 });
		}
	);
	createOperator(
		getDefaultPackage()->rootNamespace(),
		"==",
		{ type, 0 },
		{ type, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<execution::RuntimeTypeDescriptor>(a.get());
			auto arg2 = dereferenceAs<execution::RuntimeTypeDescriptor>(b.get());
			return buildBooleanValue(arg1->value() == arg2->value());
		});
	createOperator(
		getDefaultPackage()->rootNamespace(),
		"!=",
		{ type, 0 },
		{ type, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<execution::RuntimeTypeDescriptor>(a.get());
			auto arg2 = dereferenceAs<execution::RuntimeTypeDescriptor>(b.get());

			return buildBooleanValue(arg1->value() != arg2->value());
		});
	createCustomFunction(
		type
		->append<Function>("fields")
		->setReturnType({ getCollectionTypeFor({getFieldDescriptor(),0}),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			auto fields = self.type->fields();
			return convertCollection(fields, { getFieldDescriptor(), 0 });
		}
	);
	createCustomFunction(
		type
		->append<Function>("isBasedOnGeneric")
		->setReturnType({ getBool(),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return buildBooleanValue(self.type->wasGenericInstantiated());
		}
	);
	createCustomFunction(
		type
		->append<Function>("genericInstantiationInfo")
		->setReturnType({ getTypeGenericInstantiationInfo(),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return getValueFor(self.type->instantiationData());
		}
	);
	createCustomFunction(
		type
		->append<Function>("referenceCount")
		->setReturnType({ getUsize(),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return buildIntegerValue(getUsize(), self.referenceCount);
		}
	);
	createCustomFunction(
		type
		->append<Function>("baseType")
		->setReturnType({ type,0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return getValueFor(self.baseType());
		}
	);
	createCustomFunction(
		type
		->append<Function>("dereference")
		->setReturnType({ type,0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return getValueFor(self.dereference());
		}
	);

	createCustomFunction(
		type
		->append<Function>("reference")
		->setReturnType({ type,0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return getValueFor(self.reference());
		}
	);

	createCustomFunction(
		type
		->append<Function>("isVoidType")
		->setReturnType({ getBool(),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			return buildBooleanValue(self.type == nullptr);
		}
	);

	createNativeObjectGetter<TypeReference>(
		"excludedAtRuntime",
		type,
		{ getBool(), 0 },
		[](auto* v)
		{
			auto t = v->type;
			if (t == nullptr)
				return buildBooleanValue(false);
			return buildBooleanValue(v->type->metadata().hasFlag(TypeFlags::ExcludeAtRuntime));
		}
	);

	createNativeObjectGetter<TypeReference>(
		"toString",
		type,
		{ getString(), 0 },
		[](auto* v)
		{
			std::stringstream ss;
			ss << *v;
			return buildStringValue(ss.str());
		}
	);
	createNativeObjectGetter<TypeReference>(
		"name",
		type,
		{ getString(), 0 },
		[](auto* v)
		{
			return buildStringValue(v->typeName());
		}
	);
}

void completeBuildingNamespace(gsl::not_null<Type*> t)
{
	t->appendField("parent", { cMCompiler::language::getNamespaceDescriptor(), 1 })->setAccessibility(Accessibility::Public);
}

void completeBuildingFunction(gsl::not_null<Type*> t)
{
	using namespace std::string_literals;
	t->appendField("parent", { cMCompiler::language::getNamespaceDescriptor(), 1 })->setAccessibility(Accessibility::Public);
	createCustomFunction(
		t->append<Function>("parameters")
		->setReturnType({ getCollectionTypeFor({ getVariableDescriptor(), 0 }),0 }),
		t,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeFunctionDescriptor>(a["self"].get())->value();
			return getValueFor(self->parameters());
		}
	);
	createCustomFunction(
		t->append<Function>("returnType")
		->setReturnType({ getTypeDescriptor(),0 }),
		t,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeFunctionDescriptor>(a["self"].get())->value();
			return getValueFor(self->returnType());
		}
	);
	createCustomFunction(
		t->append<Function>("name")
		->setReturnType({ getString(),0 }),
		t,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeFunctionDescriptor>(a["self"].get())->value();
			return buildStringValue(self->name());
		}
	);
	createCustomFunction(
		t
		->append<Function>("isBasedOnGeneric")
		->setReturnType({ getBool(),0 }),
		t,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeFunctionDescriptor>(a["self"].get())->value();
			return buildBooleanValue(self->wasGenericInstantiated());
		}
	);
	createCustomFunction(
		t
		->append<Function>("genericInstantiationInfo")
		->setReturnType({ getFunctionGenericInstantiationInfo(),0 }),
		t,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeFunctionDescriptor>(a["self"].get())->value();
			return getValueFor(self->instantiationData());
		}
	);

	createNativeObjectGetter<Function>(
		"qualifiedName"s, t, { getString(),0 },
		[](Function* self) -> runtime_value { if (self == nullptr) return buildStringValue("NULL"); return buildStringValue((std::string)self->qualifiedName()); }
	);

	createNativeObjectGetter<Function>(
		"code"s, t, { getCollectionTypeFor({getIInstruction(), 1}),0 },
		[](Function* self) -> runtime_value { return self->code()->copy(); }
	);
	createNativeObjectGetter<Function>(
		"runtimeExecutable"s, t, { getBool(),0 },
		[](Function* self) -> runtime_value
		{
			return buildBooleanValue(!self->metadata().hasFlag(FunctionFlags::ExcludeAtRuntime));
		}
	);
	createNativeObjectGetter<Function>(
		"compiletimeExecutable"s, t, { getBool(),0 },
		[](Function* self) -> runtime_value { return buildBooleanValue(!self->metadata().hasFlag(FunctionFlags::ExcludeAtCompileTime)); }
	);
	createNativeObjectGetter<Function>(
		"isAbstract", t, { getBool(), 0 },
		[](Function* f)
		{
			auto type = dynamic_cast<Type*> (f->parent());
			return buildBooleanValue(type != nullptr && type->typeClassifier() == TypeClassifier::Interface);
		}
	);
	createNativeObjectGetter<Function>(
		"isIntrinsic", t, { getBool(), 0 },
		[](Function* f)
		{
			auto type = dynamic_cast<Type*> (f->parent());
			bool isInterfaceMetohd = (type != nullptr && type->typeClassifier() == TypeClassifier::Interface);
			return buildBooleanValue(!isInterfaceMetohd && f->code() == nullptr);
		}
	);
	createOperator(
		getDefaultPackage()->rootNamespace(),
		"==",
		{ t, 0 },
		{ t, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<execution::RuntimeFunctionDescriptor>(a.get());
			auto arg2 = dereferenceAs<execution::RuntimeFunctionDescriptor>(b.get());
			return buildBooleanValue(arg1->value() == arg2->value());
		});
	createOperator(
		getDefaultPackage()->rootNamespace(),
		"!=",
		{ t, 0 },
		{ t, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<execution::RuntimeFunctionDescriptor>(a.get());
			auto arg2 = dereferenceAs<execution::RuntimeFunctionDescriptor>(b.get());

			return buildBooleanValue(arg1->value() != arg2->value());
		});
	createNativeObjectGetter<Function>(
		"isNull", t, { getBool(), 0 },
		[](Function* f)
		{
			return buildBooleanValue(f == nullptr);
		}
	);

}

void buildGenericTypeDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto result = compilerNs->append<Type>("genericTypeDescriptor");

	createOperator(
		getDefaultPackage()->rootNamespace(),
		"==",
		TypeReference{ result, 0 },
		TypeReference{ result, 0 },
		TypeReference{ getBool(), 0 },
		[](auto& a, auto& b) -> runtime_value
		{
			auto arg1 = dereferenceAs<GenericRuntimeWrapper<Generic<Type>>>(a.get())->value();
			auto arg2 = dereferenceAs<GenericRuntimeWrapper<Generic<Type>>>(b.get())->value();
			return buildBooleanValue(arg1 == arg2);
		}
	);
}

void buildGenericFunctionDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto result = compilerNs->append<Type>("genericFunctionDescriptor");
	result->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	createOperator(
		getDefaultPackage()->rootNamespace(),
		"==",
		TypeReference{ result, 0 },
		TypeReference{ result, 0 },
		TypeReference{ getBool(), 0 },
		[](auto& a, auto& b) -> runtime_value
		{
			auto arg1 = dereferenceAs<GenericRuntimeWrapper<Generic<Function>>>(a.get())->value();
			auto arg2 = dereferenceAs<GenericRuntimeWrapper<Generic<Function>>>(b.get())->value();
			return buildBooleanValue(arg1 == arg2);
		}
	);
}

void buildTypeGenericInstantiationInfo(gsl::not_null<Namespace*> compilerNs)
{
	auto result = compilerNs->append<Type>("genericInstantiationInfo");
	result->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	using namespace cMCompiler::dataStructures::execution;
	using namespace cMCompiler::dataStructures;
	createCustomFunction(
		result
		->append<Function>("generic")
		->setReturnType({ getGenericTypeDescriptor(),0 }),
		result,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<GenericInstantiationData<Type>>>(a["self"].get())->value();
			return getValueFor(self->basedOn);
		}
	);

	createCustomFunction(
		result
		->append<Function>("parameters")
		->setReturnType({ getCollectionTypeFor({getTypeDescriptor(), 0}),0 }),
		result,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<GenericInstantiationData<Type>>>(a["self"].get())->value();
			return getValueFor(self->parameters);
		}
	);
}

void buildFunctionGenericInstantiationInfo(gsl::not_null<Namespace*> compilerNs)
{
	auto result = compilerNs->append<Type>("genericFunctionInstantiationInfo");
	using namespace cMCompiler::dataStructures::execution;
	using namespace cMCompiler::dataStructures;
	createCustomFunction(
		result
		->append<Function>("generic")
		->setReturnType({ getGenericFunctionDescriptor(),0 }),
		result,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<GenericInstantiationData<Function>>>(a["self"].get())->value();
			return getValueFor(self->basedOn);
		}
	);

	createCustomFunction(
		result
		->append<Function>("parameters")
		->setReturnType({ getCollectionTypeFor({getTypeDescriptor(), 0}),0 }),
		result,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<GenericInstantiationData<Function>>>(a["self"].get())->value();
			return getValueFor(self->parameters);
		}
	);
}

void buildCompilerLibrary(gsl::not_null<Namespace*> rootNamespace)
{
	using namespace cMCompiler::language::compileTimeFunctions;
	auto ns = rootNamespace->append<Namespace>("compiler"s);
	auto type = buildTypeDescriptor(ns);
	auto function = buildFunctionDescriptor(ns);

	auto nsDescriptor = buildNamespaceDescriptor(ns);
	buildPointerToSource(ns);
	buildFieldDescriptor(ns);
	buildPackageDescriptor(ns);
	buildGenericTypeDescriptor(ns);
	buildGenericFunctionDescriptor(ns);
	buildTypeGenericInstantiationInfo(ns);
	buildFunctionGenericInstantiationInfo(ns);
	buildIrNamespace(ns);
	completeBuildingType(type);
	completeBuildingNamespace(nsDescriptor);
	completeBuildingFunction(function);
	buildCompilerEntryPointAttribute(ns);
	appendMetadataBindings<Function>(function);
	appendMetadataBindings<TypeReference>(type);
	buildLLVMBindings(ns);
	{
		auto replace = ns->append<Function>("replaceWithCompilerFunction");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", { function, 0 });
		replace->appendVariable("name", { cMCompiler::language::getString(), 0 });
		FuntionLibrary::instance().addFunctionDefinition(replace, replaceWithCompilerFunction);
	}
	{
		auto replace = ns->append<Function>("replaceWithCompilerType");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("type", { type, 0 });
		replace->appendVariable("name", { cMCompiler::language::getString(), 0 });

		FuntionLibrary::instance().addFunctionDefinition(replace, replaceWithCompilerType);
	}
	{
		auto replace = ns->append<Function>("markCompileTimeOnly");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", { function, 0 });
		FuntionLibrary::instance().addFunctionDefinition(replace, markCompileTimeOnly);
	}
	{
		auto replace = ns->append<Function>("ignoreBody");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", { function, 0 });
		FuntionLibrary::instance().addFunctionDefinition(replace, ignoreBody);
	}
	{
		auto replace = ns->append<Function>("markRunTimeOnly");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", { function, 0 });
		FuntionLibrary::instance().addFunctionDefinition(replace, markRunTimeOnly);
	}
	{
		auto replace = ns->append<Function>("replaceWithSymbol");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", { function, 0 });
		replace->appendVariable("symbolName", { getString(), 0 });
		replace->appendVariable("assemblyPath", { getString(), 0 });
		FuntionLibrary::instance().addFunctionDefinition(replace, ReplaceWithExternalSymbol);
	}
	{
		auto replace = ns->append<Function>("replaceWithSymbol");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("type", { type, 0 });
		replace->appendVariable("symbolName", { getString(), 0 });
		replace->appendVariable("assemblyPath", { getString(), 0 });
		FuntionLibrary::instance().addFunctionDefinition(replace, ReplaceWithExternalSymbol);
	}
	{
		auto raise = ns->append<Function>("raiseError");
		raise->setAccessibility(Accessibility::Public);
		raise->appendVariable("pointerToSource", { getPointerToSource(), 1 });
		raise->appendVariable("message", { getString(), 0 });
		raise->appendVariable("code", { getUsize(), 0 });
		FuntionLibrary::instance().addFunctionDefinition(raise, raiseError);
	}
	createCustomFunction(function->append<Function>("sourceLocation")->setReturnType({ getPointerToSource(), 0 }), function,
		[](auto&& a, auto)
		{
			return dereferenceAs<RuntimeFunctionDescriptor>(a["self"].get())->value()->sourcePointer();
		});

	createCustomFunction(type->append<Function>("sourceLocation")->setReturnType({ getPointerToSource(), 0 }), type,
		[](auto&& a, auto)
		{
			return dereferenceAs<execution::RuntimeTypeDescriptor>(a["self"].get())->value().type->sourcePointer();
		});
	setAllFunctionsCompileTimeOnly(ns);
	appendPackageGetter<TypeReference>(type);
	appendPackageGetter<Function>(function);
}

void buildUsize(gsl::not_null<Type*> usize_type)
{
	using cMCompiler::language::createCustomFunction;
	using cMCompiler::language::convertToIntegral;
	using cMCompiler::dataStructures::execution::usize;
	using cMCompiler::dataStructures::Function;
	auto ns = defaultPackage__->rootNamespace();

	createOperator(
		ns,
		"+",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) + convertToIntegral<usize>(*b);
			return buildIntegerValue(usize_type, result);
		}
	);
	createOperator(
		ns,
		"-",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) - convertToIntegral<usize>(*b);
			return buildIntegerValue(usize_type, result);
		}
	);
	createOperator(
		ns,
		"*",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) * convertToIntegral<usize>(*b);
			return buildIntegerValue(usize_type, result);
		}
	);
	createOperator(
		ns,
		"/",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) / convertToIntegral<usize>(*b);
			return buildIntegerValue(usize_type, result);
		}
	);
	createOperator(
		ns,
		">",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) > convertToIntegral<usize>(*b);
			return buildBooleanValue(result);
		}
	);
	createOperator(
		ns,
		"<",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) < convertToIntegral<usize>(*b);
			return buildBooleanValue(result);
		}
	);
	createOperator(
		ns,
		"==",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto result = convertToIntegral<usize>(*a) == convertToIntegral<usize>(*b);
			return buildBooleanValue(result);
		}
	);

	createOperator(
		ns,
		"!=",
		{ usize_type, 0 },
		{ usize_type, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = convertToIntegral<usize>(*a);
			auto arg2 = convertToIntegral<usize>(*b);
			auto result = arg1 != arg2;
			return buildBooleanValue(result);
		}
	);
	using namespace std::string_literals;
	for (auto op : { "*", "+", "-", "/" })
	{
		not_null f = ns->append<Function>("operator_"s + op);
		f->appendVariable("arg1", { usize_type, 0 });
		f->appendVariable("arg2", { usize_type, 0 });
		f->setReturnType({ usize_type, 0 });
		f->metadata().appendFlag(cMCompiler::dataStructures::FunctionFlags::ExcludeAtCompileTime);
	}

	for (auto op : { "==", "!=", ">", "<"})
	{
		not_null f = ns->append<Function>("operator_"s + op);
		f->appendVariable("arg1", { usize_type, 0 });
		f->appendVariable("arg2", { usize_type, 0 });
		f->setReturnType({ getBool(), 0 });
		f->metadata().appendFlag(cMCompiler::dataStructures::FunctionFlags::ExcludeAtCompileTime);
	}


	appendCasts(ns);
}

void buildString(gsl::not_null<Type*> string)
{
	auto replace = createCustomFunction(string->append<Function>("replace"), string,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto self = dereferenceAs<StringValue>(a["self"].get());
			auto what = dereferenceAs<StringValue>(a["what"].get())->value();
			auto to = dereferenceAs<StringValue>(a["to"].get())->value();
			return buildStringValue(boost::replace_all_copy(self->value(), what, to));
		});
	replace->appendVariable("what", { string, 0 });
	replace->appendVariable("to", { string, 0 });
	replace->setReturnType({ string, 0 })->setAccessibility(Accessibility::Public);
	replace->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);


	auto plus = getDefaultPackage()->rootNamespace()->append<Function>("operator_+");
	plus->setReturnType({ string, 0 });
	plus->appendVariable("arg1", { string, 0 });
	plus->appendVariable("arg2", { string, 0 });
	cMCompiler::language::compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(
		plus,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto a1 = dereferenceAs<StringValue>(a["arg1"].get())->value();
			auto a2 = dereferenceAs<StringValue>(a["arg2"].get())->value();
			return buildStringValue(a1 + a2);
		}
	);
	plus->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);


	auto length = string->append<Function>("length");
	length->setReturnType({ getUsize(), 0 });
	createCustomFunction(
		length,
		string,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto self = dereferenceAs<StringValue>(a["self"].get());
			return buildIntegerValue(getUsize(), self->value().length());
		}
	);
	length = string->append<Function>("length")
		->setReturnType({ getUsize(), 0 });
	length->metadata().appendFlag(cMCompiler::dataStructures::FunctionFlags::ExcludeAtCompileTime);
	length->appendVariable("self", { string, 1 });

	auto indexOperator = string->append<Function>("operator_[]");
	indexOperator->setAccessibility(Accessibility::Public);
	indexOperator->setReturnType({ getChar(), 0 });
	createCustomFunction(
		indexOperator,
		string,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<StringValue>(a["self"].get());
			return buildCharValue(self->value()[convertToIntegral<size_t>(*a["index"])]);
		}
	);
	indexOperator->appendVariable("index", { getUsize(), 0 });

	indexOperator = string->append<Function>("operator_[]");
	indexOperator->setAccessibility(Accessibility::Public);
	indexOperator->setReturnType({ getChar(), 0 });
	indexOperator->appendVariable("self", { string, 1 });
	indexOperator->appendVariable("index", { getUsize(), 0 });
	indexOperator->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);



	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"==",
		{ string, 0 },
		{ string, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto const& arg1 = dereferenceAs<StringValue>(a.get())->value();
			auto const& arg2 = dereferenceAs<StringValue>(b.get())->value();
			return buildBooleanValue(arg1 == arg2);
		});

	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"!=",
		{ string, 0 },
		{ string, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto const& arg1 = dereferenceAs<StringValue>(a.get())->value();
			auto const& arg2 = dereferenceAs<StringValue>(b.get())->value();
			return buildBooleanValue(arg1 != arg2);
		});
}

void supplySourcePointers(not_null<INamedObject*> object, cMCompiler::language::runtime_value const& sourcePointer)
{
	object->setSourceLocation(sourcePointer->copy());
	for (auto child : object->children())
		supplySourcePointers(child, sourcePointer);
}

void appendLogicalConstants(not_null<Namespace*> rootNs)
{
	auto& library = compileTimeFunctions::FuntionLibrary::instance();

	library.addFunctionDefinition(
		rootNs->append<Function>("true")->setReturnType({ getBool(), 0 }),
		[](auto&&, auto)
		{
			return buildBooleanValue(true);
		}
	);
	library.addFunctionDefinition(
		rootNs->append<Function>("false")->setReturnType({ getBool(), 0 }),
		[](auto&&, auto)
		{
			return buildBooleanValue(false);
		}
	);
}

void buildPackage()
{
	using namespace cMCompiler::language::compileTimeFunctions;
	using namespace cMCompiler::language;
	auto& functionLibrary = FuntionLibrary::instance();
	using namespace std::string_literals;
	auto result = defaultPackage__.get();
	auto string = result->rootNamespace()->append<Type>("string");
	result->rootNamespace()->append<Type>("bool");
	appendLogicalConstants(result->rootNamespace());
	result->rootNamespace()->append<Type>("char");
	auto usize = result->rootNamespace()->append<Type>("usize");
	usize->metadata().appendFlag(TypeFlags::IsIntegralType);
	result->rootNamespace()->appendGeneric<Type>({ "T" },
		[](auto const& genericParameters) -> not_null<Type*>
		{
			auto name = getGenericMangledName("array", genericParameters);
			auto found = getDefaultPackage()->rootNamespace()->get<Type>(name);
			if (found != nullptr)
				return found;
			auto newType = getDefaultPackage()->rootNamespace()->append<Type>(name);
			newType->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));
			newType->setAccessibility(Accessibility::Public);
			auto indexOperator = newType->append<Function>("operator_[]");
			createIndexer(indexOperator, newType, genericParameters[0]);
			indexOperator = newType->append<Function>("operator_[]");
			indexOperator->appendVariable("self", { newType, 1 });
			indexOperator->appendVariable("index", { getUsize(), 0 });
			indexOperator->setReturnType(genericParameters[0].reference());
			indexOperator->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);
			newType->appendField("____data", {nullptr, 1});
			newType->appendField("____count", {getUsize(), 0});

			createCustomFunction(
				newType->append<Function>("push"),
				newType,
				[](auto&& args, auto)
				{
					auto self = dereferenceAs<execution::ArrayValue>(args["self"].get());
					self->push(args["value"]->copy());
					return nullptr;
				}
			)->appendVariable("value", genericParameters[0]);
			createCustomFunction(
				newType->append<Function>("length"),
				newType,
				[](auto&& args, auto)
				{
					auto self = dereferenceAs<execution::ArrayValue>(args["self"].get());
					return buildIntegerValue(getUsize(), self->size());
				}
			)->setReturnType({ getUsize(), 0 });
			auto length = newType->append<Function>("length");
			length->appendVariable("self", { newType, 1 });
			length
				->setReturnType({ getUsize(), 0 })
				->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);
			newType->setInstantiationData({ getArray(), genericParameters });
			for (auto child : newType->children())
				child->setSourceLocation(cMCompiler::language::buildPointerToSource("C-=-1_library_internals.cm", 0));
			return newType;
		}, "array", NameResolutionContext(defaultPackage__.get()),
			"C-=-1_library_internals.cm");

	result->rootNamespace()->appendGeneric<Function>({ "T" },
		[](auto a) -> Function*
		{
			return getNullFor(a.front());
		}, "null", NameResolutionContext(defaultPackage__.get()),
			"C-=-1_library_internals.cm");
	result->rootNamespace()->appendGeneric<Function>({ "T" },
		[](auto a) -> Function*
		{
			return getHeapAllocateFor(a.front());
		}, "compiletime_heap_allocate", NameResolutionContext(defaultPackage__.get()),
			"C-=-1_library_internals.cm");
	buildCompilerLibrary(result->rootNamespace());
	buildString(string);
	buildUsize(usize);
	auto readFile = result->rootNamespace()->append<Function>("read_all_file");
	readFile->appendVariable("path", { string, 0 });
	readFile->setReturnType({ string, 0 });
	readFile->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);
	functionLibrary.addFunctionDefinition(readFile, compileTimeFunctions::readAllFile);

	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"==",
		{ nullptr, 1 },
		{ nullptr, 1 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dynamic_cast<ReferenceValue*>(a.get())->value();
			auto arg2 = dynamic_cast<ReferenceValue*>(b.get())->value();
			return buildBooleanValue(arg1 == arg2);
		});
	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"!=",
		{ nullptr, 1 },
		{ nullptr, 1 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dynamic_cast<ReferenceValue*>(a.get())->value();
			auto arg2 = dynamic_cast<ReferenceValue*>(b.get())->value();
			return buildBooleanValue(arg1 != arg2);
		});
	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"==",
		{ nullptr, 2 },
		{ nullptr, 2 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dynamic_cast<ReferenceValue*>(a.get())->value();
			auto arg2 = dynamic_cast<ReferenceValue*>(b.get())->value();
			return buildBooleanValue(arg1 == arg2);
		});
	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"!=",
		{ nullptr, 2 },
		{ nullptr, 2 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dynamic_cast<ReferenceValue*>(a.get())->value();
			auto arg2 = dynamic_cast<ReferenceValue*>(b.get())->value();
			return buildBooleanValue(arg1 != arg2);
		});
	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"&&",
		{ getBool(), 0 },
		{ getBool(), 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<BooleanValue>(a.get())->value();
			auto arg2 = dereferenceAs<BooleanValue>(b.get())->value();
			return buildBooleanValue(arg1 && arg2);
		});
	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"||",
		{ getBool(), 0 },
		{ getBool(), 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<BooleanValue>(a.get())->value();
			auto arg2 = dereferenceAs<BooleanValue>(b.get())->value();
			return buildBooleanValue(arg1 || arg2);
		});

	for (auto op : { "==", "!=" })
	{
		not_null f = defaultPackage__->rootNamespace()->append<Function>("operator_"s + op);
		f->appendVariable("arg1", { nullptr, 1 });
		f->appendVariable("arg2", { nullptr, 1 });
		f->setReturnType({ getBool(), 0 });
		f->metadata().appendFlag(cMCompiler::dataStructures::FunctionFlags::ExcludeAtCompileTime);
	}

	libraries::createLibraries(defaultPackage__->rootNamespace());
	setSourcePointer(result->rootNamespace());
}

gsl::not_null<PackageDatabase*> cMCompiler::language::getDefaultPackage()
{
	static bool built = false;
	if (!built)
	{
		built = true;
		buildPackage();
	}
	return defaultPackage__.get();
}

gsl::not_null<Type*> cMCompiler::language::getBool()
{
	return defaultPackage__->rootNamespace()->get<Type>("bool");
}

gsl::not_null<cMCompiler::dataStructures::Generic<cMCompiler::dataStructures::Type>*> cMCompiler::language::getArray()
{
	return defaultPackage__->rootNamespace()->get<Generic<Type>>("array");
}

gsl::not_null<Type*> cMCompiler::language::getChar()
{
	return defaultPackage__->rootNamespace()->get<Type>("char");
}

gsl::not_null<Type*> cMCompiler::language::getUsize()
{
	return defaultPackage__->rootNamespace()->get<Type>("usize");
}

gsl::not_null<Type*> cMCompiler::language::getString()
{
	return defaultPackage__->rootNamespace()->get<Type>("string");
}

gsl::not_null<Type*> cMCompiler::language::getTypeDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("typeDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getFunctionDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("functionDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getNamespaceDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("namespaceDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getPackageDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("packageDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getFieldDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("fieldDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getPointerToSource()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("pointerToSource");
}

gsl::not_null<Type*> cMCompiler::language::getTypeGenericInstantiationInfo()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("genericInstantiationInfo");
}

gsl::not_null<Type*> cMCompiler::language::getFunctionGenericInstantiationInfo()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("genericFunctionInstantiationInfo");
}

gsl::not_null<Type*> cMCompiler::language::getGenericTypeDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("genericTypeDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getGenericFunctionDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("genericFunctionDescriptor");
}

gsl::not_null<Attribute*> cMCompiler::language::getCompilerEntryPointAttribute()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Attribute>("compilerEntryPoint");
}

gsl::not_null< cMCompiler::dataStructures::Type*> cMCompiler::language::getCollectionTypeFor(cMCompiler::dataStructures::TypeReference elementType)
{
	auto arr = getArray();
	std::vector<dataStructures::TypeReference> types;
	types.push_back(elementType);
	return instantiate(*arr, types);
}

gsl::not_null<Function*> cMCompiler::language::getNullFor(cMCompiler::dataStructures::TypeReference elementType)
{
	auto returnType = TypeReference{ elementType.type, elementType.referenceCount + 1 };
	auto existing = getDefaultPackage()->rootNamespace()->get<Function>();
	auto name = getGenericMangledName("null", { elementType });
	for (auto c : existing)
		if (c->name() == name && c->returnType() == returnType)
			return c;
	auto result = getDefaultPackage()->rootNamespace()->append<Function>(name);
	result->setReturnType(returnType);
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(result, [=](...)
		{
			return ReferenceValue::make(nullptr, elementType);
		});
	result->setInstantiationData({ getNull(), {elementType} });
	result->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));


	return result;
}

gsl::not_null<Generic<Function>*> cMCompiler::language::getNull()
{
	return getDefaultPackage()->rootNamespace()->get<Generic<Function>>("null");
}

gsl::not_null<Function*> cMCompiler::language::getHeapAllocateFor(cMCompiler::dataStructures::TypeReference objectType)
{
	auto returnType = objectType.reference();
	auto existing = getDefaultPackage()->rootNamespace()->get<Function>();
	for (auto c : existing)
		if (c->name() == "compiletime_heap_allocate" && c->returnType() == returnType)
			return c;
	auto result = getDefaultPackage()->rootNamespace()->append<Function>("compiletime_heap_allocate");
	result->setReturnType(returnType);
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(result, [=](...)
		{
			return heapAllocate(objectType, false);
		});
	result->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);
	result->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));
	return result;
}
