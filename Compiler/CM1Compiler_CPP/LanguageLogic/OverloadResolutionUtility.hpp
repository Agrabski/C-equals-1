#pragma once
#include <vector>
#include <ranges>
#include "../DataStructures/Function.hpp"
#include "../Utilities/typedRange.hpp"
#include "SpecialFunctionUtility.hpp"
#include "FunctionPredicates.hpp"

namespace cMCompiler::language
{
	struct Parameter
	{
		dataStructures::TypeReference type_;
		std::vector<not_null<dataStructures::AttributeInstance*>> attributes_;
	};

	bool verifyParameterMatch(Parameter const& parameter, dataStructures::Variable const& functionParameter);
	template<std::ranges::range ParameterRange>
	std::function<bool(not_null<dataStructures::Function const*> function)> getParameterTypeMatchPredicate(ParameterRange const& parameters)
	{
		return [parameters](not_null<dataStructures::Function const*> candidate)
		{
			auto functionParameters = candidate->parameters();
			auto isconstructor = isConstructor(candidate.get());
			if (functionParameters.size() != parameters.size() && !isconstructor
				|| (isconstructor && functionParameters.size() != parameters.size() + 1))
				return false;
			if (!isconstructor || parameters.size() > 0)
				for (auto i = 0; i < parameters.size(); i++)
					if (!verifyParameterMatch(parameters[i], *functionParameters[i + (isconstructor ? 1 : 0)]))
						return false;
			return true;
		};
	}


	dataStructures::Function* resolveOverload(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>& parameterExpressions,
		bool forceCompileTime = false, bool forceRuntime = false);
	dataStructures::Function* resolveOverloadForExecution(
		std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>& parameters,
		bool forceCompileTime = false, bool forceRuntime = false);

	template<
		std::ranges::range FunctionRange,
		std::ranges::range ParameterRange>
		dataStructures::Function* resolveOverload(
			FunctionRange const& candidates,
			ParameterRange const& parameters,
			bool forceCompileTime = false, bool forceRuntime = false)
	{
		using std::views::filter;
		auto predicate = getFunctionPredicate(forceCompileTime, forceRuntime);
		auto parameterTypeMatch = getParameterTypeMatchPredicate(parameters);
		auto r = candidates | filter(predicate) | filter(parameterTypeMatch);
		if (r.begin() != r.end())
			return *r.begin();
		return nullptr;
	}


}