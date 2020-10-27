#include "ArrayValue.hpp"
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;

std::unique_ptr<ReferenceValue> cMCompiler::dataStructures::execution::ArrayValue::getMemberValue(std::string const& name)
{
	return std::unique_ptr<ReferenceValue>();
}

Type* cMCompiler::dataStructures::execution::ArrayValue::getMemberType(std::string const& name)
{
	return nullptr;
}

void cMCompiler::dataStructures::execution::ArrayValue::setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
{
}
