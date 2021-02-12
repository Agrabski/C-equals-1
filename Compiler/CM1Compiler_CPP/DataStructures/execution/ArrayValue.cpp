#include "ArrayValue.hpp"
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;
namespace cMCompiler::language
{
	extern bool canBeAssignedTo(gsl::not_null<dataStructures::Type*> valueType, gsl::not_null<dataStructures::Type*> sinkType);
}

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

void cMCompiler::dataStructures::execution::ArrayValue::push(std::unique_ptr<IRuntimeValue>&& value)
{
	assert(language::canBeAssignedTo(value->type(), elementType_));
	allocated_.push_back(std::move(value));
}

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::ArrayValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	std::vector<json> elements;
	for (const auto& e : allocated_)
		elements.push_back(e->serialize(nameLookupFunction, manager));
	return {
		{"element_type", nameLookupFunction.get(elementType_)},
		{"value", elements}
	};
}

std::string cMCompiler::dataStructures::execution::ArrayValue::toString() const
{
	std::terminate();
	return std::string();
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::ArrayValue::copy() const
{
	std::terminate();
	return std::unique_ptr<IRuntimeValue>();
}
