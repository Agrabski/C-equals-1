#include "RuntimeTypeDescriptor.hpp"

void cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@compile_time_type value = {" << nameLookupFunction.get(value_) << "}}";
}

std::string cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::toString() const
{
	return (std::string)value_->qualifiedName();
}
