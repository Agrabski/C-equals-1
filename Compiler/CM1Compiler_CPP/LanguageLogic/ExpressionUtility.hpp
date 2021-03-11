#pragma once
#include <gsl.h>
#include "../DataStructures/Variable.hpp"
#include "runtime_values.hpp"

namespace cMCompiler::language
{
	runtime_value buildValueLiteralExpression(runtime_value&& value, runtime_value&& pointerToSource);
	runtime_value buildMethodCallExpression(
		runtime_value&& expression,
		gsl::not_null<dataStructures::Type*> type,
		std::vector<runtime_value>&& argumentExpressions,
		std::string const& methodName,
		runtime_value&& pointerToSource);
	runtime_value buildFieldAccessExpression(runtime_value&& expression, gsl::not_null<dataStructures::Field*> field, runtime_value&& pointerToSource);
	runtime_value buildVariableReferenceExpressionDescriptor(gsl::not_null<dataStructures::Variable*> var);

	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildFunctionCallExpression(
		runtime_value&& referenceToCompiletimeFunction,
		runtime_value&& referenceToRuntimeFunction,
		runtime_value&& expressions,
		runtime_value&& pointerToSource
	);


	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildConstructorInvocationExpression(
		runtime_value&& referenceToCompiletimeFunction,
		runtime_value&& referenceToRuntimeFunction,
		runtime_value&& expressions,
		runtime_value&& pointerToSource
	);

	runtime_value buildBinaryOperatorExpression(
		runtime_value&& referenceToCompiletimeFunction,
		runtime_value&& referenceToRuntimeFunction,
		runtime_value&& arg1,
		runtime_value&& arg2,
		runtime_value&& pointerToSource
	);

	void setParent(not_null<dataStructures::execution::IRuntimeValue*> expression, runtime_value&& parentReference);
}
