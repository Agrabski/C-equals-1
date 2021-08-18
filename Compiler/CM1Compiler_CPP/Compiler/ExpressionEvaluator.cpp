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
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../DataStructures/NullValueException.hpp"
#include "../LanguageLogic/TypeInstantiationUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "../LanguageLogic/GetterExecution.hpp"
#include "../LanguageLogic/TypeCoercionUtility.hpp"
using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;
using language::runtime_value;
using utilities::pointer_cast;
using language::dereferenceAs;

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateLiteral(language::runtime_value& expression)
{
	return (*language::dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_value")->value())->copy();
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateArrayLiteral(language::runtime_value& expression)
{
	auto value = language::dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_value");
	auto values = language::dereferenceAs<ArrayValue>(value.get());

	auto type = language::dereferenceAs<RuntimeTypeDescriptor>(language::dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_elementType").get());


	std::vector<language::runtime_value> result;

	for (auto& exp : *values)
		result.push_back(evaluate(exp, false));

	return language::convertCollection(std::move(result), type->value());
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateBinaryOperator(language::runtime_value& expression)
{
	not_null exp = language::dereferenceAs<ObjectValue>(expression.get());
	not_null function = language::dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeFunction").get());
	auto arg1 = pointer_cast<IRuntimeValue>(exp->getMemberValue("_arg1"));
	auto arg2 = pointer_cast<IRuntimeValue>(exp->getMemberValue("_arg2"));
	std::vector<language::runtime_value> argumentValues;
	argumentValues.push_back(evaluate(arg1, false));
	argumentValues.push_back(evaluate(arg2, false));
	return execute(function->value(), std::move(argumentValues));
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateFieldAccess(language::runtime_value& expression)
{
	auto exp = pointer_cast<IRuntimeValue>(dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_expression"));
	not_null field = language::dereferenceAs<RuntimeFieldDescriptor>(language::dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_field").get());
	auto result = evaluateLeftExpression(exp);
	return language::dereferenceAs<IComplexRuntimeValue>(result.get())->getMemberValue(field->value()->name());
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateCall(language::runtime_value& expression)
{
	not_null exp = language::dereferenceAs<ObjectValue>(expression.get());
	not_null function = language::dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeFunction").get());
	not_null arguments = language::dereferenceAs<ArrayValue>(exp->getMemberValue("_arguments").get());
	std::vector<language::runtime_value> argumentValues;
	for (auto& arg : *arguments)
		argumentValues.push_back(evaluate(arg, false));
	return execute(function->value(), std::move(argumentValues));
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateVariable(language::runtime_value& expression)
{
	auto variable = language::dereferenceAs <RuntimeVariableDescriptor>(language::dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_variable").get());
	return ReferenceValue::make(&variableLookupFunction_(variable->value()->name()), variable->value()->type());
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateGetAddress(language::runtime_value& expression)
{
	auto exp = pointer_cast<IRuntimeValue>(dereferenceAs<ObjectValue>(expression.get())->getMemberValue("_expression"));
	auto type = language::getExpressionType(expression);
	auto r = evaluateCommon(exp);
	while (r->type().referenceCount < type.referenceCount)
		r = language::moveToHeap(std::move(r));
	return r;
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateConstructor(language::runtime_value& expression)
{
	using language::dereferenceAs;
	not_null exp = dereferenceAs<ObjectValue>(expression.get());
	not_null constructor = dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeConstructor").get())->value();
	not_null arguments = dereferenceAs<ArrayValue>(exp->getMemberValue("_arguments").get());
	auto argValues = std::vector<language::runtime_value>();
	auto result = language::instantiate(constructor->parameters().front()->type());
	argValues.push_back(ReferenceValue::make(&result, result->type()));
	for (auto& arg : *arguments)
		argValues.push_back(evaluate(arg, false));
	compiler::execute(constructor, std::move(argValues));
	return result;

}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateNew(
	language::runtime_value& expression
)
{
	not_null object = language::dereferenceAs<ObjectValue>(expression.get());
	not_null newOperator = language::dereferenceAs<RuntimeFunctionDescriptor>(
		object->getMemberValue("_compiletimeNewOperator").get()
		)->value();
	not_null constructor = language::dereferenceAs<RuntimeFunctionDescriptor>(
		object->getMemberValue("_compiletimeConstructor").get()
		)->value();
	auto type = dynamic_cast<dataStructures::Type*>(constructor->parent());
	auto result = execute(newOperator, {});
	auto getValue = language::executeBasicGetter(result, "get");
	auto params = std::vector<language::runtime_value>();
	params.emplace_back(std::move(getValue));

	for (
		not_null args = language::dereferenceAs<ArrayValue>(object->getMemberValue("_arguments").get());
		auto & arg : *args
		)
		params.emplace_back(evaluate(arg, false));

	assert(execute(constructor, std::move(params)) == nullptr);
	return result;
}

std::unique_ptr<dataStructures::execution::IRuntimeValue> cMCompiler::compiler::ExpressionEvaluator::evaluateDereference(language::runtime_value& expression)
{
	not_null object = language::dereferenceAs<ObjectValue>(expression.get());
	auto exp = utilities::pointer_cast<IRuntimeValue>(object->getMemberValue("_expression"));
	auto val = evaluate(exp, false);
	return language::dereferenceOnce(val.get())->copy();
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateCommon(language::runtime_value& expression)
{
	using language::isOfType;
	if (isOfType(expression.get(), language::getLiteralExpressionDescriptor()))
		return evaluateLiteral(expression);
	if (isOfType(expression.get(), language::getFieldAccessExpressionDescriptor()))
		return evaluateFieldAccess(expression);
	if (isOfType(expression.get(), language::getFunctionCallExpressionDescriptor()))
		return evaluateCall(expression);
	if (isOfType(expression.get(), language::getVariableReferenceExpressionDescriptor()))
		return evaluateVariable(expression);
	if (isOfType(expression.get(), language::getBinaryOperatorExpressionDescriptor()))
		return evaluateBinaryOperator(expression);
	if (isOfType(expression.get(), language::getAdressofExpressionDescriptor()))
		return evaluateGetAddress(expression);
	if (isOfType(expression.get(), language::getArrayLiteralExpression()))
		return evaluateArrayLiteral(expression);
	if (isOfType(expression.get(), language::getConstructorInvocationExpressionDescriptor()))
		return evaluateConstructor(expression);
	if (isOfType(expression.get(), language::getNewExpressionDescriptor()))
		return evaluateNew(expression);
	if (isOfType(expression.get(), language::getDereferenceExpression()))
		return evaluateDereference(expression);

	std::terminate();
}


runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluate(language::runtime_value& expression, bool expectNull)
{
	auto type = language::getExpressionType(expression);
	auto result = evaluateCommon(expression);
	if (result == nullptr)
	{
		if (expectNull)
			return nullptr;
		else
		{
 			throw dataStructures::NullValueException();
		}
	}
	if (result->type() != type)
	{
		auto r = language::dereferenceOnce(result.get());
		if (r != nullptr && !language::coerce(r->type(), type))
			throw std::exception("invalid value type");
		if (r != nullptr)
			if (result == nullptr && !expectNull)
				throw dataStructures::NullValueException();
			else
				return r->copy();
		return ReferenceValue::make(nullptr, type.dereference());
	}
	else
	{
		if (result == nullptr && !expectNull)
			throw dataStructures::NullValueException();
		return result;
	}
}

std::unique_ptr<dataStructures::execution::ReferenceValue> cMCompiler::compiler::ExpressionEvaluator::evaluateLeftExpression(language::runtime_value& expression)
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
