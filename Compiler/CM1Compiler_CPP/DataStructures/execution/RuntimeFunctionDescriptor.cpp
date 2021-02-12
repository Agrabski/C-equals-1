#include "RuntimeFunctionDescriptor.hpp"

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::RuntimeFunctionDescriptor::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager&) const
{
	return {
		{"value", nameLookupFunction.get(value_)}
	};
}

std::string cMCompiler::dataStructures::execution::RuntimeFunctionDescriptor::toString() const
{
	return (std::string)value_->qualifiedName();
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeFunctionDescriptor::copy() const
{
	return std::make_unique<RuntimeFunctionDescriptor>(type(), value_);
}
