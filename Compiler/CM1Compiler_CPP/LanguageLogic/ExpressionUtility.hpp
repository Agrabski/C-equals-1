#pragma once
#include <gsl.h>
#include "../DataStructures/Variable.hpp"
#include "runtime_values.hpp"

namespace cMCompiler::language
{
	runtime_value buildValueLiteralExpression(runtime_value&& value);
	runtime_value buildMethodCallExpression(
		runtime_value&& expression,
		gsl::not_null<dataStructures::Type*> type,
		std::vector<runtime_value>&& argumentExpressions,
		std::string const& methodName,
		runtime_value&& pointerToSource);
	runtime_value buildFieldAccessExpression(runtime_value&& expression, gsl::not_null<dataStructures::Field*> field);
	runtime_value buildVariableReferenceExpressionDescriptor(gsl::not_null<dataStructures::Variable*> var);
}
