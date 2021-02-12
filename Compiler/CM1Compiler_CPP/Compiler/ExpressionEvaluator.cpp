#include "ExpressionEvaluator.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "FunctionExecutionUtility.hpp"
using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;
std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluate(dataStructures::execution::IRuntimeValue& expression)
{
	not_null type = expression.type();

	if (type.get() == language::getLiteralExpressionDescriptor().get())
	{
		return (*dynamic_cast<ObjectValue&>(expression).getMemberValue("value")->value())->copy();
	}

}
