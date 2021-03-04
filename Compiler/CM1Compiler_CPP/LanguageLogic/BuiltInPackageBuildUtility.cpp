#include "BuiltInPackageBuildUtility.hpp"
#include <boost/algorithm/string/replace.hpp>
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
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
using namespace cMCompiler::dataStructures::execution;

using namespace std::string_literals;
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;
auto const compiler_namespace__ = "compiler";
auto const compile_time_type_descriptor__ = "typeDescriptor";
auto const compile_time_function_descriptor__ = "functionDescriptor";

static auto defaultPackage__ = std::make_unique<PackageDatabase>("cm1mLang");



gsl::not_null<Type*> buildTypeDescriptor(gsl::not_null<Namespace*> compilerNs)
{
	auto type = compilerNs->append<Type>("typeDescriptor");
	type->setTypeClassifier(TypeClassifier::Class);
	type->setAccessibility(Accessibility::Public);
	type->appendField("name", cMCompiler::language::getString(), 0)->setAccessibility(Accessibility::Public);
	type->appendField("qualifiedName", cMCompiler::language::getString(), 0)->setAccessibility(Accessibility::Public);
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

gsl::not_null<Type*> buildPointerToSource(gsl::not_null<Namespace*> compilerNs)
{
	auto t = compilerNs->append<Type>("pointerToSource");
	t->setTypeClassifier(TypeClassifier::Class);
	t->setAccessibility(Accessibility::Public);
	t->appendField("filename", cMCompiler::language::getString(), 0)->setAccessibility(Accessibility::Public);
	t->appendField("lineNumber", cMCompiler::language::getUsize(), 0)->setAccessibility(Accessibility::Public);

	return t;
}

void completeBuildingType(gsl::not_null<Type*> t)
{
	t->appendField("parent", cMCompiler::language::getNamespaceDescriptor(), 1)->setAccessibility(Accessibility::Public);
}

void completeBuildingNamespace(gsl::not_null<Type*> t)
{
	t->appendField("parent", cMCompiler::language::getNamespaceDescriptor(), 1)->setAccessibility(Accessibility::Public);
}

void completeBuildingFunction(gsl::not_null<Type*> t)
{
	t->appendField("parent", cMCompiler::language::getNamespaceDescriptor(), 1)->setAccessibility(Accessibility::Public);
}

void buildCompilerLibrary(gsl::not_null<Namespace*> rootNamespace)
{
	using namespace cMCompiler::language::compileTimeFunctions;
	auto ns = rootNamespace->append<Namespace>("compiler"s);
	auto type = buildTypeDescriptor(ns);
	auto function = buildFunctionDescriptor(ns);

	auto nsDescriptor = buildNamespaceDescriptor(ns);
	completeBuildingType(type);
	completeBuildingNamespace(nsDescriptor);
	completeBuildingFunction(function);
	buildPointerToSource(ns);
	buildFieldDescriptor(ns);
	buildIrNamespace(ns);
	{
		auto replace = ns->append<Function>("replaceWithCompilerFunction");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", function, 1, cMCompiler::language::createVariableDescriptor);
		replace->appendVariable("name", cMCompiler::language::getString(), 0,
			cMCompiler::language::createVariableDescriptor);
		FuntionLibrary::instance().addFunctionDefinition(replace, replaceWithCompilerFunction);
	}
	{
		auto replace = ns->append<Function>("replaceWithCompilerType");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("type", type, 1, cMCompiler::language::createVariableDescriptor);
		replace->appendVariable("name", cMCompiler::language::getString(), 0,
			cMCompiler::language::createVariableDescriptor);

		FuntionLibrary::instance().addFunctionDefinition(replace, replaceWithCompilerType);
	}
	{
		auto replace = ns->append<Function>("markCompileTimeOnly");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", function, 1, cMCompiler::language::createVariableDescriptor);
		FuntionLibrary::instance().addFunctionDefinition(replace, markCompileTimeOnly);
	}
	{
		auto replace = ns->append<Function>("replaceWithSymbol");
		replace->setAccessibility(Accessibility::Public);
		replace->appendVariable("function", function, 1, cMCompiler::language::createVariableDescriptor);
		replace->appendVariable("symbolName", getString(), 0, cMCompiler::language::createVariableDescriptor);
		replace->appendVariable("assemblyPath", getString(), 0, cMCompiler::language::createVariableDescriptor);
		FuntionLibrary::instance().addFunctionDefinition(replace, ReplaceWithExternalSymbol);
	}
	{
		auto raise = ns->append<Function>("raiseError");
		raise->setAccessibility(Accessibility::Public);
		raise->appendVariable("pointerToSource", getPointerToSource(), 1, cMCompiler::language::createVariableDescriptor);
		raise->appendVariable("message", getString(), 1, cMCompiler::language::createVariableDescriptor);
		raise->appendVariable("code", getUsize(), 0, cMCompiler::language::createVariableDescriptor);
		FuntionLibrary::instance().addFunctionDefinition(raise, raiseError);
	}
	createCustomFunction(function->append<Function>("overridenLLVMIR")->setReturnType(getString()), function,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto llvm = dereferenceAs<execution::RuntimeFunctionDescriptor>(a["self"].get())->value()->metadata().overrideLLVMIR_;
			if (llvm)
				return buildStringValue(*llvm);
			return buildStringValue();
		})->setAccessibility(Accessibility::Public);
		auto setter = createCustomFunction(function->append<Function>("overridenLLVMIR")->setReturnType(getString()), function,
			[](value_map&& a, generic_parameters)->runtime_value
			{
				auto llvm = dereferenceAs<execution::StringValue>(a["ir"].get())->value();
				auto function = dereferenceAs<execution::RuntimeFunctionDescriptor>(a["self"].get())->value();
				function->metadata().overrideLLVMIR_ = llvm;
				function->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);
				return runtime_value();
			});
		setter->setAccessibility(Accessibility::Public);
		setter->appendVariable("ir", getString(), 0, createVariableDescriptor);

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
	replace->appendVariable("what", string, 0, cMCompiler::language::createVariableDescriptor);
	replace->appendVariable("to", string, 0, cMCompiler::language::createVariableDescriptor);
	replace->setReturnType(string)->setAccessibility(Accessibility::Public);
	replace->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);


	auto plus = getDefaultPackage()->rootNamespace()->append<Function>("operator_+");
	plus->setReturnType(string);
	plus->appendVariable("arg1", string, 0, createVariableDescriptor);
	plus->appendVariable("arg2", string, 0, createVariableDescriptor);
	cMCompiler::language::compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(
		plus,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto a1 = dereferenceAs<StringValue>(a["arg1"].get())->value();
			auto a2 = dereferenceAs<StringValue>(a["arg2"].get())->value();
			return buildStringValue(a1 + a2);
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
	result->rootNamespace()->append<Type>("usize");
	result->rootNamespace()->appendGeneric<Type>({ "T" }, nullptr, "array");
	buildCompilerLibrary(result->rootNamespace());
	buildString(string);
	auto readFile = result->rootNamespace()->append<Function>("read_all_file");
	readFile->appendVariable("path", string, 0, createVariableDescriptor);
	readFile->setReturnType(string);
	functionLibrary.addFunctionDefinition(readFile, compileTimeFunctions::readAllFile);
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

gsl::not_null<Type*> cMCompiler::language::getFieldDescriptor()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("fieldDescriptor");
}

gsl::not_null<Type*> cMCompiler::language::getPointerToSource()
{
	return defaultPackage__->rootNamespace()->get<Namespace>("compiler")->get<Type>("pointerToSource");
}

gsl::not_null< cMCompiler::dataStructures::Type*> cMCompiler::language::getCollectionTypeFor(gsl::not_null<dataStructures::Type*> elementType)
{
	auto arr = defaultPackage__->rootNamespace()->get<Generic<Type>>("array");
	std::vector<gsl::not_null<dataStructures::Type*>> types;
	types.push_back(elementType);
	return instantiate(*arr, types);
}
