#pragma once
#include <vector>
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	struct Parameter
	{
		not_null<dataStructures::Type*> type_;
		std::vector<not_null<dataStructures::AttributeInstance*>> attributes_;
	};

	bool verifyParameterMatch(Parameter const& parameter, dataStructures::Variable& functionParameter);

	dataStructures::Function* resolveOverload(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>& parameters,
		bool forceCompileTime = false, bool forceRuntime = false);


	dataStructures::Function* resolveOverload(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<Parameter> const& parameters,
		bool forceCompileTime = false, bool forceRuntime = false);


	bool isCompiletimeExecutable(not_null<dataStructures::Function const*> function);
	bool isRuntimeExecutable(not_null<dataStructures::Function const*> function);
	std::function<bool(not_null<dataStructures::Function const*> function)> getFunctionPredicate(bool forceCompileTime = false, bool forceRuntime = false);
}