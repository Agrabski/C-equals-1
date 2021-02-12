#include "StatementEvaluator.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "FunctionExecutionUtility.hpp"

void cMCompiler::compiler::StatementEvaluator::evaluate(language::runtime_value& instruction)
{
	using language::isOfType;
	if (isOfType(instruction.get(), cMCompiler::language::getFunctionCallExpressionDescriptor()))
		call(instruction);
	std::terminate();
}

void cMCompiler::compiler::StatementEvaluator::call(language::runtime_value& instruction)
{
	ev_.evaluate(*instruction.get());
}
