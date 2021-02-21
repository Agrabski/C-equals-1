#include "ExpressionUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "IRUtility.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "OverloadResolutionUtility.hpp"

cMCompiler::language::runtime_value cMCompiler::language::buildValueLiteralExpression(runtime_value&& value)
{
	auto result = instantiate(getLiteralExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("value", std::move(value));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::buildMethodCallExpression(
	runtime_value&& expression,
	gsl::not_null<dataStructures::Type*> type,
	std::vector<runtime_value>&& argumentExpressions,
	std::string const& methodName,
	runtime_value&& pointerToSource)
{
	argumentExpressions.insert(argumentExpressions.begin(), std::move(expression));

	auto methods = type->methods();
	methods.erase(std::remove_if(methods.begin(), methods.end(), [&](auto const e) {return e->name() != methodName; }));

	return buildFunctionCall(
		getValueFor(resolveOverload(methods, argumentExpressions, true, false)),
		getValueFor(resolveOverload(methods, argumentExpressions, false, true)),
		language::convertToCollection(std::move(argumentExpressions), getExpressionDescriptor()),
		std::move(pointerToSource));
	return runtime_value();
}

cMCompiler::language::runtime_value cMCompiler::language::buildFieldAccessExpression(runtime_value&& expression, gsl::not_null<dataStructures::Field*> field)
{
	auto result = instantiate(getFieldAccessExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("_field", getValueFor(field));
	object->setValue("_expression", std::move(expression));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::buildVariableReferenceExpressionDescriptor(gsl::not_null<dataStructures::Variable*> var)
{
	auto result = instantiate(getVariableReferenceExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("_variable", createVariableDescriptor(var));
	object->setValue("_type", createTypeDescriptor(var->type()));
	return result;
}
