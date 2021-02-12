#include "RuntimeTypeDescriptor.hpp"

using namespace cMCompiler::dataStructures::execution;

std::string cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::typeName() const
{
	return "runtime_type_descriptor";
}

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager&) const
{
	return {
		{"value", nameLookupFunction.get(value_)}
	};
}

std::string cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::toString() const
{
	return (std::string)value_->qualifiedName();
}

std::unique_ptr<IRuntimeValue> RuntimeTypeDescriptor::copy() const
{
	auto result = std::make_unique<RuntimeTypeDescriptor>(type(), value_);
	return result;
}

std::unique_ptr<ReferenceValue> cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::getMemberValue(std::string const& name)
{
	return value_->acutalObject()->getMemberValue(name);
}

cMCompiler::dataStructures::Type* cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::getMemberType(std::string const& name)
{
	return value_->acutalObject()->getMemberType(name);
}

void cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
{
	std::terminate(); // todo: report error
}
