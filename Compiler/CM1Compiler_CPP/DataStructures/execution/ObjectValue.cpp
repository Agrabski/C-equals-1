#include "ObjectValue.hpp"
#include "../Type.hpp"
#include <sstream>

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
	stream << "{type = " << type()->qualifiedName() << " ";
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

bool cMCompiler::dataStructures::execution::ObjectValue::validate(IRuntimeValue* value, std::string const& name)
{
	auto fields = type()->fields();
	auto field = std::find_if(fields.begin(), fields.end(), [&](auto const& e) {return e->name() == name; });
	return field != fields.end() && (*field)->type() == value->type();
}

cMCompiler::dataStructures::Type* cMCompiler::dataStructures::execution::ObjectValue::getMemberType(std::string const& name)
{
	auto fields = type()->fields();
	auto field = (std::find_if(fields.begin(), fields.end(), [&](const auto e) {return e->name() == name; }));
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
