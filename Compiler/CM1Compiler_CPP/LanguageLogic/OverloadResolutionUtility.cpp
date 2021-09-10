#include "OverloadResolutionUtility.hpp"
#include "GetterExecution.hpp"
#include "SpecialFunctionUtility.hpp"
#include "TypeCoercionUtility.hpp"
#include "../Utilities/typedRange.hpp"
#include "../Utilities/algorithm.hpp"


using namespace cMCompiler::dataStructures;
using cMCompiler::utilities::typed_range;

bool cMCompiler::language::verifyParameterMatch(Parameter const& parameter, dataStructures::Variable const& functionParameter)
{
	if (functionParameter.type().type == nullptr && functionParameter.type().referenceCount == parameter.type_.referenceCount)
		return true;
	if (!coerce(parameter.type_, functionParameter.type()))
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

void cMCompiler::language::setOverloadResolutionInformation(not_null<dataStructures::Type*> type, std::vector<TypeReference> const& genericParameters)
{
	if (utilities::has_if(genericParameters, [](auto const& e) { return e.type->metadata().hasFlag(TypeFlags::ExcludeAtRuntime); }))
		type->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
}

void cMCompiler::language::setOverloadResolutionInformation(not_null<dataStructures::Function*> function, std::vector<TypeReference> const& genericParameters)
{
	if (utilities::has_if(genericParameters, [](auto const& e) { return e.type->metadata().hasFlag(TypeFlags::ExcludeAtRuntime); }))
		function->metadata().appendFlag(FunctionFlags::ExcludeAtRuntime);
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

