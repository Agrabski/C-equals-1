#include "ReferenceValue.hpp"

std::string cMCompiler::dataStructures::execution::ReferenceValue::typeName() const
{
	return "reference_value";
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
cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::ReferenceValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		{"value", manager.serializeReference(*value_)}
	};
}