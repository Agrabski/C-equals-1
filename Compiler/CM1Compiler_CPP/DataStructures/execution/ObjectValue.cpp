#include "ObjectValue.hpp"
#include <sstream>
#include <optional>
#include "../Type.hpp"

namespace cMCompiler::language
{
	struct CoercionStrategy
	{

	};
	extern std::optional<CoercionStrategy> coerce(dataStructures::TypeReference const& valueType, dataStructures::TypeReference const& sinkType);
	extern unsigned char countReferenceLevel(dataStructures::execution::IRuntimeValue const* value);

}

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::ObjectValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	std::vector<json> properties;
	for (const auto& v : values_)
		properties.push_back({ v.first, v.second->serialize(nameLookupFunction, manager) });
	return {
		{"fields", properties}
	};
}

std::string cMCompiler::dataStructures::execution::ObjectValue::toString() const
{
	auto stream = std::stringstream();
	stream << "{type = " << type() << " ";
	for (auto const& kv : values_)
	{

		stream << kv.first << " = ";
		if (kv.second != nullptr)
			stream << kv.second->toString();
		stream << "NULL";
	}
	stream << "}";
	return stream.str();
}

bool cMCompiler::dataStructures::execution::ObjectValue::validate(IRuntimeValue* value, std::string const& name) const
{
	if (value == nullptr)
		return true;
	auto fields = type().type->fields();
	auto field = std::find_if(fields.begin(), fields.end(), [&](auto const& e) noexcept {return e->name() == name; });
	if (field->get()->type().type == nullptr)
		return true; // allow any type in interpreted mode if type is null. Only for compiler internals
	return field != fields.end() &&
		language::coerce(value->type(), (*field)->type());
}

cMCompiler::dataStructures::TypeReference const& cMCompiler::dataStructures::execution::ObjectValue::getMemberType(std::string const& name) const
{
	auto fields = type().type->fields();
	auto field = (std::find_if(fields.begin(), fields.end(), [&](const auto e) noexcept {return e->name() == name; }));
	assert(field != fields.end());
	return (*field)->type();
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::ObjectValue::copy() const
{
	auto result = std::make_unique<ObjectValue>(type());
	for (auto const& kv : values_)
		result->values_[kv.first] = kv.second->copy();
	return result;
}
