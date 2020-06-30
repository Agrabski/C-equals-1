#include "StringValue.hpp"

void cMCompiler::dataStructures::execution::StringValue::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@integer_literal type = ";
	stream << nameLookupFunction.get(type());
	stream << " value = \'" << value_ << "\'}";
}

std::string cMCompiler::dataStructures::execution::StringValue::toString() const
{
	return value_;
}
