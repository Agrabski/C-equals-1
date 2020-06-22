#pragma once
#include <vector>
#include "NameResolver.hpp"
#include "../DataStructures/Attribute.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"

namespace cMCompiler::language
{
	dataStructures::AttributeInstance* getAttribute(dataStructures::AttributeTarget& target, dataStructures::Attribute* attribute);
	bool isCompileTime(dataStructures::Function& f);
}