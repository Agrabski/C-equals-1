#include "OverloadResolutionUtility.hpp"
#include "GetterExecution.hpp"
#include "SpecialFunctionUtility.hpp"
#include "../Utilities/typedRange.hpp"

using namespace cMCompiler::dataStructures;
using cMCompiler::utilities::typed_range;

bool cMCompiler::language::verifyParameterMatch(Parameter const& parameter, dataStructures::Variable const& functionParameter)
{
	if (functionParameter.type().type == nullptr && functionParameter.type().referenceCount == parameter.type_.referenceCount)
		return true;
	if (parameter.type_ != functionParameter.type())
		return false;
	for (auto attribute : functionParameter.attributes())
		if (!std::any_of(parameter.attributes_.begin(), parameter.attributes_.end(), [&](not_null<dataStructures::AttributeInstance*> e)
			{
				//todo: better attribute comparison
				return e->basedOn() == attribute->basedOn();
			}))
			return false;
			return true;
}

Function* cMCompiler::language::resolveOverload(
	std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>& parameters,
	bool forceCompileTime, bool forceRuntime)
{
	using namespace std::string_literals;
	auto params = std::vector<Parameter>();
	for (auto& p : parameters)
		params.push_back({ executeGetter<TypeReference>(p, "type"s) });
	return resolveOverload(candidates, params, forceCompileTime, forceRuntime);
	if (candidates.size() == 1)
		return candidates.front();
	//todo: do it actually
}

cMCompiler::dataStructures::Function* cMCompiler::language::resolveOverloadForExecution(
	std::vector<gsl::not_null<dataStructures::Function*>> const& candidates,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>& parameters,
	bool forceCompileTime, bool forceRuntime)
{
	using namespace std::string_literals;
	auto params = std::vector<Parameter>();
	for (auto& p : parameters)
		params.push_back({ p->type() });
	return resolveOverload(candidates, params, forceCompileTime, forceRuntime);
	if (candidates.size() == 1)
		return candidates.front();

}

bool cMCompiler::language::isCompiletimeExecutable(not_null<Function const*> function)
{
	return function->metadata().hasFlag(dataStructures::FunctionFlags::ExcludeAtCompileTime);
}

bool cMCompiler::language::isRuntimeExecutable(not_null<Function const*> function)
{
	return function->metadata().hasFlag(dataStructures::FunctionFlags::ExcludeAtRuntime);
}

std::function<bool(not_null<Function const*>function)> cMCompiler::language::getFunctionPredicate(bool forceCompileTime, bool forceRuntime)
{
	return [=](not_null<Function const*> f) -> bool
	{
		auto result = true;
		if (forceCompileTime)
			result = result && isCompiletimeExecutable(f);
		if (forceRuntime)
			result = result && isRuntimeExecutable(f);
		return result;
	};
}
