#pragma once
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../DataStructures/execution/StringValue.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"
#include "AttributeUtility.hpp"


namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IntegerValue> buildIntegerValue(dataStructures::Type* ofType);
	std::unique_ptr<dataStructures::execution::IntegerValue> buildIntegerValue(dataStructures::Type* ofType, dataStructures::execution::usize value);
	std::unique_ptr<dataStructures::execution::IntegerValue> buildIntegerValue(dataStructures::Type* ofType, dataStructures::execution::number_component* value, size_t valueSize);
	std::unique_ptr<dataStructures::execution::StringValue> buildStringValue();
	std::unique_ptr<dataStructures::execution::StringValue> buildStringValue(std::string const& value);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildLiteral(dataStructures::Type* ofType, std::string value);
	std::unique_ptr<dataStructures::execution::BooleanValue> buildBooleanValue(bool value);
}