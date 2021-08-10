#include "ArrayValue.hpp"
#include "../IValueHolder.hpp"
#include <optional>
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;
namespace cMCompiler::language
{
	struct CoercionStrategy
	{

	};
	extern std::optional<CoercionStrategy> coerce(TypeReference const& valueType, TypeReference const& sinkType);

}

std::unique_ptr<ReferenceValue> cMCompiler::dataStructures::execution::ArrayValue::getMemberValue(std::string const& name)
{
	return std::unique_ptr<ReferenceValue>();
}

TypeReference const& cMCompiler::dataStructures::execution::ArrayValue::getMemberType(std::string const& name) const
{
	std::terminate();
}

void cMCompiler::dataStructures::execution::ArrayValue::setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
{
}

void cMCompiler::dataStructures::execution::ArrayValue::push(std::unique_ptr<IRuntimeValue>&& value)
{
	assert(language::coerce(value->type(), elementType_));
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
	using namespace std::string_literals;
	auto result = "["s;
	for (auto const& e : allocated_)
		result += e->toString() + " ,";
	if (allocated_.size() >= 1)
	{
		result.erase(result.end() - 1);
		result.erase(result.end() - 1);
	}
	result += "]";
	return result;
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::ArrayValue::copy() const
{
	auto result = std::make_unique<ArrayValue>(type(), elementType_);
	for (auto& e : allocated_)
		result->push(e->copy());
	return result;
}
