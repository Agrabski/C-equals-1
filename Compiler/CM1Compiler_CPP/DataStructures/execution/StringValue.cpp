#include "StringValue.hpp"

std::string cMCompiler::dataStructures::execution::StringValue::typeName() const
{
	return "string_value";
}

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::StringValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		{"value", value_}
	};
}

std::string cMCompiler::dataStructures::execution::StringValue::toString() const
{
	return value_;
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::StringValue::copy() const
{
	auto result = std::make_unique<StringValue>(type());
	result->value_ = value_;
	return result;
}
