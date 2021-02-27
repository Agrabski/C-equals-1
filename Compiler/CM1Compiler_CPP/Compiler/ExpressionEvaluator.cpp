#include "ExpressionEvaluator.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateLiteral(dataStructures::execution::IRuntimeValue& expression)
{
	return (*language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_value")->value())->copy();
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateFieldAccess(dataStructures::execution::IRuntimeValue& expression)
{
	auto exp = language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_expression");
	not_null field = language::dereferenceAs<RuntimeFieldDescriptor>(language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_field").get());
	auto result = evaluate(*exp.get());
	return language::dereferenceAs<IComplexRuntimeValue>(result.get())->getMemberValue(field->value()->name());
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateCall(dataStructures::execution::IRuntimeValue& expression)
{
	not_null exp = language::dereferenceAs<ObjectValue>(&expression);
	not_null function = language::dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compileTimeFunction").get());
	not_null arguments = language::dereferenceAs<ArrayValue>(exp->getMemberValue("_arguments").get());
	std::vector<language::runtime_value> argumentValues;
	for (auto& arg : *arguments)
		argumentValues.push_back(evaluate(*arg));
	return execute(function->value(), std::move(argumentValues));
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateVariable(dataStructures::execution::IRuntimeValue& expression)
{
	auto variable = language::dereferenceAs <RuntimeVariableDescriptor>(language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_variable").get());
	return ReferenceValue::make(&variableLookupFunction_(variable->value()->name()), variable->value()->type());
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateCommon(dataStructures::execution::IRuntimeValue& expression)
{
	not_null e = language::dereference(&expression);
	using language::isOfType;
	if (isOfType(e, language::getLiteralExpressionDescriptor()))
		return evaluateLiteral(*e);
	if (isOfType(e, language::getFieldAccessExpressionDescriptor()))
		return evaluateFieldAccess(*e);
	if (isOfType(e, language::getFunctionCallExpressionDescriptor()))
		return evaluateCall(*e);
	if (isOfType(e, language::getVariableReferenceExpressionDescriptor()))
		return evaluateVariable(*e);

	std::terminate();
}


std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluate(dataStructures::execution::IRuntimeValue& expression)
{
	auto result = evaluateCommon(expression);
	if (result == nullptr)
		return nullptr;
	return language::dereferenceOnce(result.get())->copy();
}

std::unique_ptr<dataStructures::execution::ReferenceValue> cMCompiler::compiler::ExpressionEvaluator::evaluateLeftExpression(dataStructures::execution::IRuntimeValue& expression)
{
	auto result =  evaluateCommon(expression);
	auto reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(result.get());
	if (reference != nullptr)
	{
		result.release();
		return std::unique_ptr<ReferenceValue>(reference);
	}
	std::terminate();
}
