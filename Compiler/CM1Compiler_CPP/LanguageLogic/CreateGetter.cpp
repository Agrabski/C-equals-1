#include "CreateGetter.hpp"
#include "CompileTimeFunctions/FunctionLibrary.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "../DataStructures/Function.hpp"

using cMCompiler::language::runtime_value;
using namespace cMCompiler::dataStructures;

gsl::not_null<Function*> cMCompiler::language::createGetter(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type)
{
	auto f = [=](
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, not_null<dataStructures::Type*>> genericParameters
		) -> std::unique_ptr<dataStructures::execution::IRuntimeValue>
	{
		auto reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(valueMap["self"].get());
		return dynamic_cast<dataStructures::execution::IComplexRuntimeValue*>(reference->value()->get())
			->getMemberValue("_" + function->name());
	};
	return createCustomFunction(function, type, f);
}

gsl::not_null<Function*> cMCompiler::language::createCustomFunction(
	gsl::not_null<dataStructures::Function*> function,
	gsl::not_null<dataStructures::Type*> type,
	std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>(std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, not_null<dataStructures::Type*>>genericParameters)> body)
{
	function->appendVariable("self", { type, 1 });
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(function, body);
	function->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);
	return function;
}


void cMCompiler::language::createIndexer(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type, dataStructures::TypeReference returnType)
{
	function->appendVariable("self", { type, 1 });
	function->appendVariable("index", { getUsize(), 0 });
	function->setReturnType(returnType );
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

void cMCompiler::language::createOperator(
	gsl::not_null<Namespace*> ns,
	std::string const& kind,
	TypeReference type1,
	TypeReference type2,
	TypeReference returnType,
	std::function<runtime_value(runtime_value& arg1, runtime_value& arg2)> body)
{
	auto f = ns->append<Function>("operator_" + kind);
	f->appendVariable("arg1", type1);
	f->appendVariable("arg2", type2);
	f->setReturnType(returnType);
	f->confirm();
	f->finalize();

	auto function = [=](
		value_map&& valueMap,
		generic_parameters genericParameters
		) -> runtime_value
	{
		auto arg1 = &valueMap["arg1"];
		auto arg2 = &valueMap["arg2"];
		return body(*arg1, *arg2);
	};
	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(f, function);

}
