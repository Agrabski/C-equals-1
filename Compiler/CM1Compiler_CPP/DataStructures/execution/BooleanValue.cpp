#include "BooleanValue.hpp"

using namespace cMCompiler::dataStructures::execution;

std::string cMCompiler::dataStructures::execution::BooleanValue::toString() const
{
	return value_ ? "true" : "false";
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::BooleanValue::copy() const
{
	auto result = std::make_unique<BooleanValue>(type());
	result->value(value_);
	return result;
}

std::string cMCompiler::dataStructures::execution::BooleanValue::typeName() const
{
	return "boolean";
}

json cMCompiler::dataStructures::execution::BooleanValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return json();
}
