#include "ExpressionEvaluator.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluate(gsl::not_null<dataStructures::ir::IExpression*> expression)
{
	expression->accept(*this);
	return std::move(value_);
}

std::unique_ptr<dataStructures::execution::ReferenceValue> cMCompiler::compiler::ExpressionEvaluator::evaluateLValue(gsl::not_null<dataStructures::ir::IExpression*> expression)
{
	makeReference_ = true;
	expression->accept(*this);
	return std::unique_ptr<dataStructures::execution::ReferenceValue>(dynamic_cast<ReferenceValue*>(value_.release()));
}

void cMCompiler::compiler::ExpressionEvaluator::visit(cMCompiler::dataStructures::ir::ValueLiteralExpression& expression)
{
	value_ = expression.value();
}

void cMCompiler::compiler::ExpressionEvaluator::visit(cMCompiler::dataStructures::ir::VariableReferenceExpression& expression)
{
	value_ = variableLookupFunction_(expression.variable()->name())->copy();
}
