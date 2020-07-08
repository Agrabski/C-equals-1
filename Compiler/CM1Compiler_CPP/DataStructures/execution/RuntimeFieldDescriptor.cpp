#include "RuntimeFieldDescriptor.hpp"
#include "../Field.hpp"
#include "../Type.hpp"

using namespace cMCompiler::dataStructures::execution;

void cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@compile_time_field value = {" << nameLookupFunction.get(value_->type()) + value_->name() << "}}";
}

std::string cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::toString() const
{
	return (std::string) (value_->type()->qualifiedName() + value_->name());
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::copy() const
{
	return std::make_unique<RuntimeFieldDescriptor>(type(), value_);
}
