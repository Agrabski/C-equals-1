#include "RuntimeVariableDescriptor.hpp"

std::string cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::typeName() const
{
	return "runtime_variable_descriptor";
}

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager&) const
{
	return {
		{"value" , nameLookupFunction.get(value_)}
	};
}

std::string cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::toString() const
{
	return "{ variable: " + value_->name() + " defined in: " + value_->parent()->name() + " }";
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::copy() const
{
	return std::make_unique<RuntimeVariableDescriptor>(type(), value_);
}

std::unique_ptr<cMCompiler::dataStructures::execution::ReferenceValue> cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::getMemberValue(std::string const& name)
{
	std::terminate();
	//return dynamic_cast<IComplexRuntimeValue*>(value_->object().get())->getMemberValue(name);
}


void cMCompiler::dataStructures::execution::RuntimeVariableDescriptor::setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
{
	std::terminate();
}