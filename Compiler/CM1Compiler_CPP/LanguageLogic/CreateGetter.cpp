#include "CreateGetter.hpp"
#include "CompileTimeFunctions/FunctionLibrary.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"

gsl::not_null<cMCompiler::dataStructures::Function*> cMCompiler::language::createGetter(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type)
{
	function->appendVariable("self", type, cMCompiler::language::createVariableDescriptor);
	auto f = [=](
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, not_null<dataStructures::Type*>> genericParameters
		) -> std::unique_ptr<dataStructures::execution::IRuntimeValue>
	{
		auto reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(valueMap["self"].get());
		return dynamic_cast<dataStructures::execution::IComplexRuntimeValue*>(reference->value()->get())
			->getMemberValue("_" + function->name());
	};
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(function, f);
	return function;
}

void cMCompiler::language::createIndexer(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type, gsl::not_null<dataStructures::Type*> returnType)
{
	function->appendVariable("self", type, language::createVariableDescriptor);
	function->appendVariable("index", getUsize(), language::createVariableDescriptor);
	function->setReturnType(returnType);
	auto f = [=](
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, not_null<dataStructures::Type*>> genericParameters
		)->std::unique_ptr<dataStructures::execution::IRuntimeValue>
	{
		auto index = convertToIntegral<size_t>(*valueMap["index"]);
		auto reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(valueMap["self"].get());
		return dynamic_cast<dataStructures::execution::ArrayValue*>(reference->value()->get())->get(index);
	};
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(function, f);
}
