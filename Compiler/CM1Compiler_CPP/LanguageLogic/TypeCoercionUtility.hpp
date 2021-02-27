#pragma once
#include <gsl.h>
#include <optional>
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	struct CoercionStrategy
	{

	};
	std::optional<CoercionStrategy> coerce(
		gsl::not_null<dataStructures::Type*> valueType,
		unsigned char valueReferenceLevel,
		unsigned char sinkReferenceLevel,
		gsl::not_null<dataStructures::Type*> sinkType);

	unsigned char countReferenceLevel(dataStructures::execution::IRuntimeValue const* value);
}