#pragma once
#include <vector>
#include "NameResolver.hpp"
#include "../DataStructures/Attribute.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"

namespace cMCompiler::language
{
	std::vector<std::unique_ptr<dataStructures::AttributeInstance>> getAttributes(
		not_null<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext*> attributeSequence, 
		dataStructures::INamedObject* context,
		NameResolver&nr);
}