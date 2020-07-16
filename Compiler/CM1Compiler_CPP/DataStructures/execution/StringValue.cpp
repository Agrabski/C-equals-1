#include "StringValue.hpp"

void cMCompiler::dataStructures::execution::StringValue::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@string_literal type = ";
	stream << nameLookupFunction.get(type());
	stream << " value = \'" << value_ << "\'}";
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
