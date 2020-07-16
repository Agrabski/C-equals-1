#pragma once
#include <vector>
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	dataStructures::Function* resolveOverload(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>> const& parameters,
		bool forceCompileTime = false, bool allowCompileTimeOnly = false);

	dataStructures::Function* resolveOverload(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<std::unique_ptr<dataStructures::ir::IExpression>> const& parameters,
		bool forceCompileTime = false, bool allowCompileTimeOnly = false);
}