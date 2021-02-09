#pragma once
#include <gsl.h>
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	bool canBeAssignedTo(gsl::not_null<dataStructures::Type*> valueType, gsl::not_null<dataStructures::Type*> sinkType);
}