#include "RuntimeFunctionDescriptor.hpp"

void cMCompiler::dataStructures::execution::RuntimeFunctionDescriptor::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@compile_time_function value = {" << nameLookupFunction.get(value_) << "}}";
}

std::string cMCompiler::dataStructures::execution::RuntimeFunctionDescriptor::toString() const
{
	return (std::string)value_->qualifiedName();
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeFunctionDescriptor::copy() const
{
	return std::make_unique<RuntimeFunctionDescriptor>(type(), value_);
}
