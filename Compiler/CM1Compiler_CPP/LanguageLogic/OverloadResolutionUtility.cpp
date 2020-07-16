#include "OverloadResolutionUtility.hpp"

cMCompiler::dataStructures::Function* cMCompiler::language::resolveOverload(
	std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>> const& parameters,
	bool forceCompileTime, bool allowCompileTimeOnly)
{
	if (candidates.size() == 1)
		return candidates.front();
	//todo: do it actually
}


cMCompiler::dataStructures::Function* cMCompiler::language::resolveOverload(std::vector<gsl::not_null<dataStructures::Function*>> const& candidates, std::vector<std::unique_ptr<dataStructures::ir::IExpression>> const& parameters, bool forceCompileTime, bool allowCompileTimeOnly)
{
	if (candidates.size() == 1)
		return candidates.front();
}
