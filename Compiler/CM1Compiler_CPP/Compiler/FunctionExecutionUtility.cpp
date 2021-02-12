#include "FunctionExecutionUtility.hpp"
#include "ExpressionEvaluator.hpp"
#include "StatementEvaluator.hpp"
#include "../LanguageLogic/CompileTimeFunctions/FunctionLibrary.hpp"
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> findValue(IRuntimeValue* value, std::vector<std::unique_ptr<IRuntimeValue>> values)
{
	auto result = std::find_if(values.begin(), values.end(), [&](auto const& e) noexcept {return e.get() == value; });
	if (result != values.end())
		return std::move(*result);
	return nullptr;
}

std::unique_ptr<IRuntimeValue> cMCompiler::compiler::execute(
	gsl::not_null<dataStructures::Function*> functionDefinition,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap)
{
	std::unique_ptr<IRuntimeValue> returnValue = nullptr;
	auto f = language::compileTimeFunctions::FuntionLibrary::instance().getFunction(functionDefinition);
	if (f)
	{
		auto values = std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
		int i = 0;
		for (not_null const var : functionDefinition->parameters())
			values[var->name()] = std::move(valueMap[i++]);
		return (*f)(std::move(values), std::map<std::string, not_null<dataStructures::Type*>>());
	}
	std::map<std::string ,std::unique_ptr<IRuntimeValue>> locals;
	auto& instructions = functionDefinition->code();
	auto const variableLookup = [functionDefinition, &locals, &valueMap](auto const& name) -> std::unique_ptr<IRuntimeValue>&
	{
		auto local = locals.find(name);
		if (local != locals.end())
			return local->second;
		auto parameters = functionDefinition->parameters();
		auto parameter = std::find_if(begin(parameters), end(parameters), [&](auto const e) noexcept {return e->name() == name; });
		if (parameter != parameters.end())
			return valueMap[parameter - begin(parameters)];
	};
	auto eval = ExpressionEvaluator(variableLookup);
	auto statementEvaluator = StatementEvaluator(*functionDefinition, eval, locals);
	for (auto& instruction : *instructions)
		statementEvaluator.evaluate(instruction);

	return returnValue;
}