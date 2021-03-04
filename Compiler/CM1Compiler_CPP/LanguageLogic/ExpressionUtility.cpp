#include "ExpressionUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "IRUtility.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "OverloadResolutionUtility.hpp"

cMCompiler::language::runtime_value cMCompiler::language::buildValueLiteralExpression(runtime_value&& value, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getLiteralExpressionDescriptor());
	object.setValue("_value", std::move(value));
	object.setValue("_pointerToSource", std::move(pointerToSource));

	return std::move(result);
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildFunctionCallStatement(
	runtime_value&& referenceToCompiletimeFunction,
	runtime_value&& referenceToRuntimeFunction,
	runtime_value&& expressions,
	runtime_value&& pointerToSource)
{
	auto expression = buildFunctionCallExpression(
		std::move(referenceToCompiletimeFunction),
		std::move(referenceToRuntimeFunction),
		std::move(expressions),
		pointerToSource->copy());

	auto [result, resultObject] = heapAllocateObject(getFunctionCallStatementDescriptor());
	resultObject.setValue("_function", std::move(expression));
	return std::move(result);
}


cMCompiler::language::runtime_value cMCompiler::language::buildMethodCallExpression(
	runtime_value&& expression,
	gsl::not_null<dataStructures::Type*> type,
	std::vector<runtime_value>&& argumentExpressions,
	std::string const& methodName,
	runtime_value&& pointerToSource)
{
	argumentExpressions.insert(argumentExpressions.begin(), std::move(expression));

	std::vector<not_null<dataStructures::execution::IRuntimeValue*>> expressions;
	for (auto& e : argumentExpressions)
		expressions.push_back(e.get());

	auto methods = type->methods();
	methods.erase(std::remove_if(methods.begin(), methods.end(), [&](auto const e) {return e->name() != methodName; }));

	auto result = buildFunctionCallExpression(
		getValueFor(resolveOverload(methods, argumentExpressions, true, false)),
		getValueFor(resolveOverload(methods, argumentExpressions, false, true)),
		language::convertToCollection(std::move(argumentExpressions), getExpressionDescriptor(), 1),
		std::move(pointerToSource));
	assert(dynamic_cast<dataStructures::execution::ReferenceValue*>(result.get()) != nullptr);
	for (auto arg : expressions)
		setParent(arg, result->copy());
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildFieldAccessExpression(runtime_value&& expression, gsl::not_null<dataStructures::Field*> field, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getFieldAccessExpressionDescriptor());
	object.setValue("_field", getValueFor(field));
	object.setValue("_expression", std::move(expression));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildVariableReferenceExpressionDescriptor(gsl::not_null<dataStructures::Variable*> var)
{
	auto [result, object] = heapAllocateObject(getVariableReferenceExpressionDescriptor());
	object.setValue("_variable", createVariableDescriptor(var));
	object.setValue("_type", createTypeDescriptor(var->type()));
	return std::move(result);
}

void cMCompiler::language::setParent(not_null<dataStructures::execution::IRuntimeValue*> expression, runtime_value&& parentReference)
{
	if (parentReference != nullptr)
	{
		not_null complex = dereferenceAs<dataStructures::execution::IComplexRuntimeValue>(expression.get());
		complex->setValue("_parentExpression", std::move(parentReference));
	}
}
