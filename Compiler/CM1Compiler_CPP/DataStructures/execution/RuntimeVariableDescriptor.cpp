#include "RuntimeVariableDescriptor.hpp"

std::string cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::toString() const
{
	return "{ variable: " + value_->name() + " }";
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::copy() const
{
	return std::make_unique<RuntimeVariableDescriptor>(type(), value_);
}

std::unique_ptr<cMCompiler::dataStructures::execution::ReferenceValue> cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::getMemberValue(std::string const& name)
{
	return value_->object()->getMemberValue(name);
}

cMCompiler::dataStructures::Type* cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::getMemberType(std::string const& name)
{
	return value_->object()->getMemberType(name);
}

void cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
{
	std::terminate();
}