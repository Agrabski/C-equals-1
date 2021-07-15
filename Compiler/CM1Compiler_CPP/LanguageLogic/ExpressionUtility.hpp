#pragma once
#include <gsl.h>
#include "../DataStructures/Variable.hpp"
#include "NameResolver.hpp"
#include "runtime_values.hpp"

namespace cMCompiler::language
{
	runtime_value buildAdressofExpression(runtime_value&& value, runtime_value&& pointerToSource);


	runtime_value buildValueLiteralExpression(runtime_value&& value, runtime_value&& pointerToSource);
	runtime_value buildArrayLiteralExpression(
		runtime_value&& expressions,
		dataStructures::TypeReference valueType,
		runtime_value&& pointerToSource);
	runtime_value buildMethodCallExpression(
		runtime_value&& expression,
		dataStructures::TypeReference type,
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

	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildNewExpression(
		runtime_value&& referenceToruntimeNew,
		runtime_value&& referenceTocompiletimeNew,
		runtime_value&& referenceToRuntimeConstructor,
		runtime_value&& referenceToCompiletimeContructor,
		runtime_value&& expressions,
		runtime_value&& pointerToSource
	);

	runtime_value buildIndexOperatorExpression(
		runtime_value&& expression,
		dataStructures::TypeReference type,
		std::vector<runtime_value>&& argumentExpressions,
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

	runtime_value buildBinaryOperatorExpression(
		NameResolver& nr,
		NameResolutionContext& context,
		std::string operatorKind,
		runtime_value&& arg1,
		runtime_value&& arg2,
		runtime_value&& pointerToSource
	);


	void setParent(not_null<dataStructures::execution::IRuntimeValue*> expression, runtime_value&& parentReference);
}
