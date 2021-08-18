#pragma once
#include <gsl/gsl>
#include <optional>
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	struct CoercionStrategy
	{

	};
	std::optional<CoercionStrategy> coerce(dataStructures::TypeReference const& valueType, dataStructures::TypeReference const& sinkType);

}