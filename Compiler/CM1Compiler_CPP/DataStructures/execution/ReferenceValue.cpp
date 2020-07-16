#include "ReferenceValue.hpp"

void cMCompiler::dataStructures::execution::ReferenceValue::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@reference value = " << value_ << " }";
}

std::string cMCompiler::dataStructures::execution::ReferenceValue::toString() const
{
	return (*value_)->toString();
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::ReferenceValue::copy() const
{
	return std::make_unique<ReferenceValue>(value_, type());
}

void cMCompiler::dataStructures::execution::ReferenceValue::performAssigment(std::unique_ptr<IRuntimeValue>&& newValue)
{
	*value_ = std::move(newValue);
}
