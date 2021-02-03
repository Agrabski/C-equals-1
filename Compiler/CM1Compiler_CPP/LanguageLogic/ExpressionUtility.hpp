#pragma once
#include <gsl.h>
#include "../DataStructures/Variable.hpp"
#include "runtime_values.hpp"

namespace cMCompiler::language
{
	runtime_value buildValueLiteralExpression(runtime_value&& value);
	runtime_value buildValueMemberAccessExpression(runtime_value&& variableReference, runtime_value&& memberAccessChain);
	runtime_value buildVariableReferenceExpression(gsl::not_null<dataStructures::Variable*> var);
}
