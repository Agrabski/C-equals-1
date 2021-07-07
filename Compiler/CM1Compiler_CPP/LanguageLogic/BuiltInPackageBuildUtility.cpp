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
using namespace cMCompiler::dataStructures::execution;

using namespace std::string_literals;
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;
auto const compiler_namespace__ = "compiler";
auto const compile_time_type_descriptor__ = "typeDescriptor";
auto const compile_time_function_descriptor__ = "functionDescriptor";

static auto defaultPackage__ = std::make_unique<PackageDatabase>("cm1mLang");


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
	return type;
}

gsl::not_null<Type*> buildFunctionDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto function = compilerNs->append<Type>("functionDescriptor");
	function->setTypeClassifier(TypeClassifier::Class);
	function->setAccessibility(Accessibility::Public);
	return function;
}

gsl::not_null<Type*> buildNamespaceDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto ns = compilerNs->append<Type>("namespaceDescriptor");
	ns->setTypeClassifier(TypeClassifier::Class);
	ns->setAccessibility(Accessibility::Public);
	return ns;
}

gsl::not_null<Type*> buildPackageDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	using cMCompiler::dataStructures::execution::RuntimePackageDescriptor;
	auto ns = compilerNs->append<Type>("packageDescriptor");
	ns->setTypeClassifier(TypeClassifier::Class);
	ns->setAccessibility(Accessibility::Public);

	createCustomFunction(
		ns->append<Function>("getAllTypes")->setReturnType({ getCollectionTypeFor({ getTypeDescriptor(), 0 }), 1 }),
		ns,
		[](auto&& args, auto)
		{
			auto self = dereferenceAs<RuntimePackageDescriptor>(args["self"].get())->value();
			return convertCollection(self->getAllTypes(), { getTypeDescriptor(), 0 });
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

	return ns;
}

gsl::not_null<Type*> buildPointerToSource(gsl::not_null<Namespace*> compilerNs)
{
	auto t = compilerNs->append<Type>("pointerToSource");
	t->setTypeClassifier(TypeClassifier::Class);
	t->setAccessibility(Accessibility::Public);
	t->appendField("filename", { cMCompiler::language::getString(), 0 })->setAccessibility(Accessibility::Public);
	t->appendField("lineNumber", { cMCompiler::language::getUsize(), 0 })->setAccessibility(Accessibility::Public);

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
		->append<Function>("constructors")
		->setReturnType({ getCollectionTypeFor({ cMCompiler::language::getFunctionDescriptor(), 0 }),0 }),
		type,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeTypeDescriptor>(a["self"].get())->value();
			auto methods = self.type->methods();
			if (!methods.empty())
				methods.erase(std::remove_if(methods.begin(), methods.end(), isConstructor));
			return convertCollection(methods, { getFunctionDescriptor(), 0 });
		}
	)->setAccessibility(Accessibility::Public);
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
}

void completeBuildingNamespace(gsl::not_null<Type*> t)
{
	t->appendField("parent", { cMCompiler::language::getNamespaceDescriptor(), 1 })->setAccessibility(Accessibility::Public);
}

void completeBuildingFunction(gsl::not_null<Type*> t)
{
	t->appendField("parent", { cMCompiler::language::getNamespaceDescriptor(), 1 })->setAccessibility(Accessibility::Public);
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
	completeBuildingType(type);
	completeBuildingNamespace(nsDescriptor);
	completeBuildingFunction(function);
	buildIrNamespace(ns);
	buildCompilerEntryPointAttribute(ns);
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
	createCustomFunction(function->append<Function>("overridenLLVMIR")->setReturnType({ getString(), 0 }), function,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto llvm = dereferenceAs<execution::RuntimeFunctionDescriptor>(a["self"].get())->value()->metadata().overrideLLVMIR_;
			if (llvm)
				return buildStringValue(*llvm);
			return buildStringValue();
		}
	)->setAccessibility(Accessibility::Public);
	auto setter = createCustomFunction(function->append<Function>("overridenLLVMIR")->setReturnType({ getString(), 0 }), function,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto llvm = dereferenceAs<execution::StringValue>(a["ir"].get())->value();
			auto function = dereferenceAs<execution::RuntimeFunctionDescriptor>(a["self"].get())->value();
			function->metadata().overrideLLVMIR_ = llvm;
			function->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);
			return runtime_value();
		});
	setter->setAccessibility(Accessibility::Public);
	setter->appendVariable("ir", { getString(), 0 });
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
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
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
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
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
		{ usize_type, 0 },
		[usize_type](auto& a, auto& b)
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
		[usize_type](auto& a, auto& b)
		{
			auto arg1 = convertToIntegral<usize>(*a);
			auto arg2 = convertToIntegral<usize>(*b);
			auto result = arg1 != arg2;
			return buildBooleanValue(result);
		}
	);
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

	cMCompiler::language::createOperator(
		defaultPackage__->rootNamespace(),
		"==",
		{ string, 0 },
		{ string, 0 },
		{ getBool(), 0 },
		[](auto& a, auto& b)
		{
			auto arg1 = dereferenceAs<StringValue>(a.get())->value();
			auto arg2 = dereferenceAs<StringValue>(b.get())->value();
			return buildBooleanValue(arg1 == arg2);
		});
}

void supplySourcePointers(not_null<INamedObject*> object, cMCompiler::language::runtime_value const& sourcePointer)
{
	object->setSourceLocation(sourcePointer->copy());
	for (auto child : object->children())
		supplySourcePointers(child, sourcePointer);
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
	result->rootNamespace()->append<Type>("char");
	auto usize = result->rootNamespace()->append<Type>("usize");
	result->rootNamespace()->appendGeneric<Type>({ "T" },
		[](auto a)
		{
			return getCollectionTypeFor(a.front());
		}, "array", NameResolutionContext(defaultPackage__.get()),
			"C-=-1_library_internals.cm");

	result->rootNamespace()->appendGeneric<Function>({ "T" },
		[](auto a) -> Function*
		{
			return getNullFor(a.front());
		}, "null", NameResolutionContext(defaultPackage__.get()),
			"C-=-1_library_internals.cm");
	buildCompilerLibrary(result->rootNamespace());
	buildString(string);
	buildUsize(usize);
	auto readFile = result->rootNamespace()->append<Function>("read_all_file");
	readFile->appendVariable("path", { string, 0 });
	readFile->setReturnType({ string, 0 });
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
	supplySourcePointers(result->rootNamespace(), buildPointerToSource("C-=-1_library_internals.cm", 0));
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
	for (auto c : existing)
		if (c->name() == "null" && c->returnType() == returnType)
			return c;
	auto result = getDefaultPackage()->rootNamespace()->append<Function>("null");
	result->setReturnType(returnType);
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(result, [=](...)
		{
			return ReferenceValue::make(nullptr, returnType);
		});
	return result;
}
