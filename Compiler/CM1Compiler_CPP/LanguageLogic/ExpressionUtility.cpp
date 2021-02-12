#include "ExpressionUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "IRUtility.hpp"
#include "MetatypeUility.hpp"

cMCompiler::language::runtime_value cMCompiler::language::buildValueLiteralExpression(runtime_value&& value)
{
	auto result = instantiate(getLiteralExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("value", std::move(value));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::buildValueMemberAccessExpression(runtime_value&& variableReference, runtime_value&& memberAccessChain)
{
	auto result = instantiate(getValueMemberAccessExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("_variable", std::move(variableReference));
	object->setValue("_memberAccessChain", std::move(memberAccessChain));
	return result;

	std::terminate();
	return runtime_value();
}


cMCompiler::language::runtime_value cMCompiler::language::buildVariableReferenceExpression(gsl::not_null<dataStructures::Variable*> var)
{
	auto result = instantiate(getVariableReferenceExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("_variable", createVariableDescriptor(var));
	object->setValue("_type", createTypeDescriptor(var->type()));
	return result;
}
