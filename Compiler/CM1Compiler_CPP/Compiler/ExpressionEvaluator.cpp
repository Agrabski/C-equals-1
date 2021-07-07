#include "ExpressionEvaluator.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../LanguageLogic/TypeInstantiationUtility.hpp"
using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateLiteral(dataStructures::execution::IRuntimeValue& expression)
{
	return (*language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_value")->value())->copy();
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateArrayLiteral(dataStructures::execution::IRuntimeValue& expression)
{
	auto value = language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_value");
	auto values = language::dereferenceAs<ArrayValue>(value.get());

	auto type = language::dereferenceAs<RuntimeTypeDescriptor>(language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_elementType").get());


	std::vector<language::runtime_value> result;

	for (auto& exp : *values)
		result.push_back(evaluate(*exp));

	return language::convertCollection(std::move(result), type->value());
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateBinaryOperator(dataStructures::execution::IRuntimeValue& expression)
{
	not_null exp = language::dereferenceAs<ObjectValue>(&expression);
	not_null function = language::dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeFunction").get());
	not_null arg1 = language::dereferenceAs<ObjectValue>(exp->getMemberValue("_arg1").get());
	not_null arg2 = language::dereferenceAs<ObjectValue>(exp->getMemberValue("_arg2").get());
	std::vector<language::runtime_value> argumentValues;
	argumentValues.push_back(evaluate(*arg1));
	argumentValues.push_back(evaluate(*arg2));
	return execute(function->value(), std::move(argumentValues));
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateFieldAccess(dataStructures::execution::IRuntimeValue& expression)
{
	auto exp = language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_expression");
	not_null field = language::dereferenceAs<RuntimeFieldDescriptor>(language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_field").get());
	auto result = evaluateLeftExpression(*exp.get());
	return language::dereferenceAs<IComplexRuntimeValue>(result.get())->getMemberValue(field->value()->name());
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateCall(dataStructures::execution::IRuntimeValue& expression)
{
	not_null exp = language::dereferenceAs<ObjectValue>(&expression);
	not_null function = language::dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeFunction").get());
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

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateGetAddress(dataStructures::execution::IRuntimeValue& expression)
{
	auto exp = language::dereferenceAs<ObjectValue>(&expression)->getMemberValue("_expression");
	return evaluateCommon(*exp);
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateConstructor(dataStructures::execution::IRuntimeValue& expression)
{
	using language::dereferenceAs;
	not_null exp = dereferenceAs<ObjectValue>(&expression);
	not_null constructor = dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeConstructor").get())->value();
	not_null arguments = dereferenceAs<ArrayValue>(exp->getMemberValue("_arguments").get());
	auto argValues = std::vector<language::runtime_value>();
	auto result = language::instantiate(constructor->parameters().front()->type());
	argValues.push_back(ReferenceValue::make(&result, result->type()));
	for (auto const& arg : *arguments)
		argValues.push_back(evaluate(*arg));
	compiler::execute(constructor, std::move(argValues));
	return result;

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
	if (isOfType(e, language::getBinaryOperatorExpressionDescriptor()))
		return evaluateBinaryOperator(*e);
	if (isOfType(e, language::getAdressofExpressionDescriptor()))
		return evaluateGetAddress(*e);
	if (isOfType(e, language::getArrayLiteralExpression()))
		return evaluateArrayLiteral(*e);
	if (isOfType(e, language::getConstructorInvocationExpressionDescriptor()))
		return evaluateConstructor(*e);
	if (isOfType(e, language::getNewExpressionDescriptor()))
		return evaluateNew(*e);

	std::terminate();
}


std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluate(dataStructures::execution::IRuntimeValue& expression)
{
	auto result = evaluateCommon(expression);
	if (result == nullptr)
		return nullptr;
	if (!language::isOfType(&expression, language::getAdressofExpressionDescriptor()))
	{
		auto r = language::dereferenceOnce(result.get());
		if (r != nullptr)
			return r->copy();
		return ReferenceValue::make(nullptr, { result->type().type, result->type().referenceCount - 1 });
	}
	else
		return result;
}

std::unique_ptr<dataStructures::execution::ReferenceValue> cMCompiler::compiler::ExpressionEvaluator::evaluateLeftExpression(dataStructures::execution::IRuntimeValue& expression)
{
	auto result = evaluateCommon(expression);
	auto reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(result.get());
	if (reference != nullptr)
	{
		result.release();
		return std::unique_ptr<ReferenceValue>(reference);
	}
	std::terminate();
}
