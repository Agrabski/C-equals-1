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
	auto interfaces = valueType.type->interfaces();
	for (auto interf : valueType.type->interfaces())
	{
		auto strategy = coerce({ interf, valueType.referenceCount }, sinkType);
		if (strategy)
			return strategy; // todo: merge strategies
	}
	return std::optional<CoercionStrategy>();
}

unsigned char cMCompiler::language::countReferenceLevel(dataStructures::execution::IRuntimeValue const* value)
{
	// todo: nulls will mess this up. Too bad!
	auto ref = dynamic_cast<dataStructures::execution::ReferenceValue const*>(value);
	if (ref != nullptr)
		return 1 + countReferenceLevel(ref->value()->get());
	return 0;
}
