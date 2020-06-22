#include "FunctionExecutionUtility.hpp"
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> findValue(IRuntimeValue* value, std::vector<std::unique_ptr<IRuntimeValue>> values)
{
	auto result = std::find_if(values.begin(), values.end(), [&](auto const& e) noexcept {return e.get() == value; });
	if (result != values.end())
		return std::move(*result);
	return nullptr;
}

std::unique_ptr<IRuntimeValue> cMCompiler::compiler::execute(gsl::not_null<dataStructures::Function*> functionDefinition, std::map<std::string, dataStructures::execution::IRuntimeValue*> valueMap)
{
	std::vector<std::unique_ptr<IRuntimeValue>> locals;
	auto instructions = functionDefinition->code();
	for (auto instruction : instructions)
	{

	}
	std::terminate();
}
