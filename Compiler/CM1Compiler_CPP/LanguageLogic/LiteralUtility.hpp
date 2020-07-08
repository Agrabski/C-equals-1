#pragma once
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../DataStructures/execution/StringValue.hpp"
#include "AttributeUtility.hpp"


namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IntegerValue> buildIntegerValue(dataStructures::Type* ofType);
	std::unique_ptr<dataStructures::execution::StringValue> buildStringValue();
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildLiteral(dataStructures::Type* ofType, std::string value);
}