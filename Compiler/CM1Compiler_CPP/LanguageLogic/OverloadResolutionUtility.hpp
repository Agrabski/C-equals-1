#pragma once
#include <vector>
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	dataStructures::Function* resolveOverload(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<gsl::not_null<dataStructures::Variable*>> const& parameters,
		bool forceCompileTime = false, bool allowCompileTimeOnly = false);
}