#include "RuntimeFieldDescriptor.hpp"
#include <sstream>
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
	std::stringstream result;
	result << value_->type() << " " << value_->name();
	return result.str();
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::RuntimeFieldDescriptor::copy() const
{
	return std::make_unique<RuntimeFieldDescriptor>(type(), value_);
}
