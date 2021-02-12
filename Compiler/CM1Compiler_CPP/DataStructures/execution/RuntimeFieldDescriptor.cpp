#include "RuntimeFieldDescriptor.hpp"
#include "../Field.hpp"
#include "../Type.hpp"

using namespace cMCompiler::dataStructures::execution;


cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager&) const
{
	return {
		"value", nameLookupFunction.get(value_)
	};
}

std::string cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::toString() const
{
	return (std::string) (value_->type()->qualifiedName() + value_->name());
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::copy() const
{
	return std::make_unique<RuntimeFieldDescriptor>(type(), value_);
}
