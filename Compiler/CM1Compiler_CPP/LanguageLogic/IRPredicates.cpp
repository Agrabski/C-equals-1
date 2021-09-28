#include "IRPredicates.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "IRUtility.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"

bool cMCompiler::language::expressionIsCompileTimeExecutable(
	not_null<dataStructures::execution::IRuntimeValue*> value,
	std::map<not_null<dataStructures::Variable*>, runtime_value> const& valueMap)
{
	using namespace dataStructures::execution;
	not_null object = dereferenceAs<ObjectValue>(value);
	if (isOfType(object, getLiteralExpressionDescriptor()))
		return true;
	if (isOfType(object, getBinaryOperatorExpressionDescriptor()))
	{
		auto function = dereferenceAs<RuntimeFunctionDescriptor>(object->getMemberValue("_compiletimeFunction").get());
		return
			function != nullptr &&
			function->value() != nullptr &&
			expressionIsCompileTimeExecutable(object->getMemberValue("_arg1").get(), valueMap) &&
			expressionIsCompileTimeExecutable(object->getMemberValue("_arg2").get(), valueMap)
			;
	}
	if (isOfType(object, getVariableReferenceExpressionDescriptor()))
	{
		auto variable = dereferenceAs<RuntimeVariableDescriptor>(object->getMemberValue("_variable").get())->value();
		return valueMap.contains(variable);
	}
}