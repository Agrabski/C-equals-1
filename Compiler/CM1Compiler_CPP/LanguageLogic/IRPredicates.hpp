#pragma once
#include <gsl/gsl>
#include <map>
#include "../DataStructures/Variable.hpp"
#include "runtime_values.hpp"


using gsl::not_null;

namespace cMCompiler::language
{
	bool expressionIsCompileTimeExecutable(
		not_null<dataStructures::execution::IRuntimeValue*>value,
		std::map<not_null<dataStructures::Variable*>, runtime_value>const& valueMap);
}
