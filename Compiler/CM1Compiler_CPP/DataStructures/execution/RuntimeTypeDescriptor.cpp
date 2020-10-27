#include "RuntimeTypeDescriptor.hpp"

using namespace cMCompiler::dataStructures::execution;

void cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@compile_time_type value = {" << nameLookupFunction.get(value_) << "}}";
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
