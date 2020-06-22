#pragma once
#include "../DataStructures/execution/IntegerValue.hpp"
#include "AttributeUtility.hpp"


namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IntegerValue> buildIntegerValue(dataStructures::Type* ofType);
}