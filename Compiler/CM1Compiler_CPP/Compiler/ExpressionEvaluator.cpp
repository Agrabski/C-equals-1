#include "ExpressionEvaluator.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "FunctionExecutionUtility.hpp"
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

void cMCompiler::compiler::ExpressionEvaluator::visit(dataStructures::ir::MemberAccessExpression& expression)
{
	auto initialValue = evaluate(expression.initialExpression());
	not_null reference = dynamic_cast<ReferenceValue*>(initialValue.get());
	auto members = expression.memberChain();
	IRuntimeValue* tmp = reference->value()->get();
	for (auto s = members.begin(); s + 1 != members.end(); s++)
	{
		not_null object = dynamic_cast<ObjectValue*>(tmp);
		tmp = object->getMemberValue(*s).get();
	}
	not_null object = dynamic_cast<ObjectValue*>(tmp);
	if (makeReference_)
		value_ = std::make_unique<ReferenceValue>(
			&(object->getMemberValue(members.back())),
			object->getMemberType(members.back()));
	else
		value_ = object->getMemberValue(members.back())->copy();
}

void cMCompiler::compiler::ExpressionEvaluator::visit(dataStructures::ir::FunctionCall& expression)
{
	auto parameters = std::vector<std::unique_ptr<IRuntimeValue>>();
	for (auto const& param : expression.parameters())
		parameters.push_back(evaluate(param.get()));
	auto result = execute(expression.compileTimeFunction(), std::move(parameters), resolver_, context_);
}

void cMCompiler::compiler::ExpressionEvaluator::visit(cMCompiler::dataStructures::ir::ValueLiteralExpression& expression)
{
	if (makeReference_)
		throw std::exception(); //todo: exception
	value_ = expression.value();
}

void cMCompiler::compiler::ExpressionEvaluator::visit(cMCompiler::dataStructures::ir::VariableReferenceExpression& expression)
{
	using dataStructures::execution::ReferenceValue;
	auto& variable = variableLookupFunction_(expression.variable()->name());
	if (makeReference_)
		if (dynamic_cast<ReferenceValue*>(variable.get()) == nullptr)
			value_ = std::make_unique<ReferenceValue>(
				&(variableLookupFunction_(expression.variable()->name())),
				expression.variable()->type());
		else
			value_ = variable->copy();
	else
		value_ = variableLookupFunction_(expression.variable()->name())->copy();
}
