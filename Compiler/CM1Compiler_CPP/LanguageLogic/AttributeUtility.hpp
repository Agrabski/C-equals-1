#pragma once
#include <vector>
#include "NameResolver.hpp"
#include "../DataStructures/Attribute.hpp"
#include "../DataStructures/TypeReference.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"

namespace cMCompiler::language
{
	dataStructures::AttributeInstance* getAttribute(dataStructures::AttributeTarget& target, dataStructures::Attribute* attribute);
	std::function<bool(not_null<dataStructures::AttributeInstance*>att)> getIsDescribedByTypePredicate(dataStructures::TypeReference type);
}