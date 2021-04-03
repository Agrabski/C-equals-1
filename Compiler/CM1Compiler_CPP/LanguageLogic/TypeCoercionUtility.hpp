#pragma once
#include <gsl.h>
#include <optional>
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	struct CoercionStrategy
	{

	};
	std::optional<CoercionStrategy> coerce(dataStructures::TypeReference const& valueType, dataStructures::TypeReference const& sinkType);

	unsigned char countReferenceLevel(dataStructures::execution::IRuntimeValue const* value);
}