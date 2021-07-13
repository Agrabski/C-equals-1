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
#include "../LanguageLogic/TypeInstantiationUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
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
		result.push_back(evaluate(exp));

	return language::convertCollection(std::move(result), type->value());
}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateBinaryOperator(language::runtime_value& expression)
{
	not_null exp = language::dereferenceAs<ObjectValue>(expression.get());
	not_null function = language::dereferenceAs<RuntimeFunctionDescriptor>(exp->getMemberValue("_compiletimeFunction").get());
	auto arg1 = pointer_cast<IRuntimeValue>(exp->getMemberValue("_arg1"));
	auto arg2 = pointer_cast<IRuntimeValue>(exp->getMemberValue("_arg2"));
	std::vector<language::runtime_value> argumentValues;
	argumentValues.push_back(evaluate(arg1));
	argumentValues.push_back(evaluate(arg2));
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
		argumentValues.push_back(evaluate(arg));
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
	auto r = evaluateCommon(exp);
	if(r->type().referenceCount == 0)
		return language::moveToHeap(std::move(r));
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
		argValues.push_back(evaluate(arg));
	compiler::execute(constructor, std::move(argValues));
	return result;

}

runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluateNew(
	language::runtime_value& expression
)
{
	not_null object = language::dereferenceAs<ObjectValue>(expression.get());
	not_null constructor = language::dereferenceAs<RuntimeFunctionDescriptor>(
		object->getMemberValue("_compiletimeConstructor").get()
		)->value();
	auto type = dynamic_cast<dataStructures::Type*>(constructor->parent());
	auto result = language::heapAllocate({ type, 0 }, false);
	auto params = std::vector<language::runtime_value>();
	params.emplace_back(result->copy());

	for (
		not_null args = language::dereferenceAs<ArrayValue>(object->getMemberValue("_arguments").get());
		auto & arg : *args
		)
		params.emplace_back(evaluate(arg));

	assert(execute(constructor, std::move(params)) == nullptr);
	return result;
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

	std::terminate();
}


runtime_value cMCompiler::compiler::ExpressionEvaluator::evaluate(language::runtime_value& expression)
{
	auto type = language::getExpressionType(expression);
	auto result = evaluateCommon(expression);
	if (result == nullptr)
		return nullptr;
	if (!language::isOfType(expression.get(), language::getAdressofExpressionDescriptor()))
	{
		auto r = language::dereferenceOnce(result.get());
		if (r != nullptr && type != r->type())
			throw std::exception("invalid value type");
		if (r != nullptr)
			return r->copy();
		return ReferenceValue::make(nullptr, { result->type().type, result->type().referenceCount - 1 });
	}
	else
		return result;
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
