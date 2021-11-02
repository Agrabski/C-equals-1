#include "RuntimeTypesConversionUtility.hpp"
#include "LiteralUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include <algorithm>
#include "../DataStructures/execution/ObjectValue.hpp"
#include "../DataStructures/execution/StringValue.hpp"

using namespace cMCompiler::dataStructures;

SourcePointer cMCompiler::language::convertToSourcePointer(not_null<execution::IRuntimeValue*> value)
{
	auto object = dereferenceAs<execution::ObjectValue>(value);
	return SourcePointer(
		convertToString(*object->getMemberValue("filename")->value()->get()),
		convertToIntegral<unsigned long long>(*object->getMemberValue("lineNumber")->value()->get())
	);
}

std::string cMCompiler::language::convertToString(dataStructures::execution::IRuntimeValue& value)
{
	auto& string = dynamic_cast<execution::StringValue&>(value);
	return string.toString();
}

cMCompiler::language::runtime_value cMCompiler::language::convertToCollection(std::vector<runtime_value>&& values, dataStructures::TypeReference type)
{
	auto result = std::make_unique<execution::ArrayValue>(TypeReference{ getCollectionTypeFor(type),0 }, type);
	for (auto& v : values)
		result->push(std::move(v));
	return result;
}


cMCompiler::language::runtime_value cMCompiler::language::convertToCollection(std::vector<std::string> const& strings)
{
	auto result = std::make_unique<execution::ArrayValue>(TypeReference{ getCollectionTypeFor({ getString(), 0 }),0 }, dataStructures::TypeReference{ getString(), 0 });
	for (auto const& s : strings)
		result->push(buildStringValue(s));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::convertCollection(std::vector<runtime_value>&& collection, dataStructures::TypeReference elementType)
{
	auto result = std::make_unique<dataStructures::execution::ArrayValue>(TypeReference{ getCollectionTypeFor(elementType),0 }, elementType);
	for (auto& e : collection)
		result->push(std::move(e));
	return result;
}

bool cMCompiler::language::canCastReference(gsl::not_null<dataStructures::Type*> from, gsl::not_null<dataStructures::Type*> to)
{
	if (from == to)
		return true;
	auto& interfaces = from->interfaces();
	return std::any_of(interfaces.begin(), interfaces.end(), [to](auto const& e) {return canCastReference(e, to); });
}

cMCompiler::dataStructures::execution::IRuntimeValue* cMCompiler::language::dereference(not_null<dataStructures::execution::IRuntimeValue*> value)
{
	using namespace cMCompiler::dataStructures::execution;
	ReferenceValue* ref = nullptr;
	dataStructures::execution::IRuntimeValue* v = value.get();
	do
	{
		ref = dynamic_cast<ReferenceValue*>(v);
		if (ref == nullptr)
			return v;

		if (ref->value() != nullptr)
			v = ref->value()->get();
	} while (ref->value() != nullptr);
	return nullptr;
}

cMCompiler::dataStructures::execution::IRuntimeValue* cMCompiler::language::dereferenceOnce(not_null<dataStructures::execution::IRuntimeValue*> value)
{
	using namespace cMCompiler::dataStructures::execution;
	auto ref = dynamic_cast<ReferenceValue*>(value.get());
	if (ref == nullptr)
		return value;
	auto refValue = ref->value();
	if (refValue == nullptr)
		return nullptr;
	return ref->value()->get();
}
