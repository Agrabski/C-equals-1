#include "TypeCoercionUtility.hpp"
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;

std::optional<CoercionStrategy> cMCompiler::language::coerce(TypeReference const& valueType, TypeReference const& sinkType)
{
	if (valueType.referenceCount != sinkType.referenceCount)
		return std::optional<CoercionStrategy>();
	if (valueType == sinkType)
		return CoercionStrategy{};
	if (valueType.referenceCount < 1)
		return std::optional<CoercionStrategy>();
	for (auto const& interf : valueType.type->interfaces())
	{
		auto strategy = coerce({ interf, valueType.referenceCount }, sinkType);
		if (strategy)
			return strategy; // todo: merge strategies
	}
	return std::optional<CoercionStrategy>();
}

