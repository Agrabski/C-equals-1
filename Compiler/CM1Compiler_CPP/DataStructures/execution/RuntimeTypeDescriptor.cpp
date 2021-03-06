#include "RuntimeTypeDescriptor.hpp"
#include <sstream>

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
	std::stringstream result;
	result << value_;
	return result.str();
}

std::unique_ptr<IRuntimeValue> RuntimeTypeDescriptor::copy() const
{
	auto result = std::make_unique<RuntimeTypeDescriptor>(type(), value_);
	return result;
}

std::unique_ptr<ReferenceValue> cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::getMemberValue(std::string const& name)
{
	std::terminate();
}

void cMCompiler::dataStructures::execution::RuntimeTypeDescriptor::setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
{
	std::terminate(); // todo: report error
}
