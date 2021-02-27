#include "TypeCoercionUtility.hpp"
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;

std::optional<CoercionStrategy> cMCompiler::language::coerce(gsl::not_null<Type*> valueType, unsigned char valueReferenceLevel, unsigned char sinkReferenceLevel, gsl::not_null<Type*> sinkType)
{
	if (valueReferenceLevel != sinkReferenceLevel)
		return std::optional<CoercionStrategy>();
	if (valueType == sinkType )
		return CoercionStrategy{};
	if (valueReferenceLevel < 1)
		return std::optional<CoercionStrategy>();
	auto interfaces = valueType->interfaces();
	for (auto interf : valueType->interfaces())
	{
		auto strategy = coerce(interf, valueReferenceLevel, sinkReferenceLevel, sinkType);
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
