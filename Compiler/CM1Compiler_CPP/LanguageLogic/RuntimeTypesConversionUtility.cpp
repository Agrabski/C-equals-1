#include "RuntimeTypesConversionUtility.hpp"
#include "LiteralUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include <algorithm>
#include "../DataStructures/execution/ObjectValue.hpp"
#include "../DataStructures/execution/StringValue.hpp"

using namespace cMCompiler::dataStructures;

SourcePointer cMCompiler::language::convertToSourcePointer(execution::IRuntimeValue& value)
{
	auto& object = dynamic_cast<execution::ObjectValue&>(value);
	return SourcePointer(
		convertToString(*object.getMemberValue("lineNumber")->value()->get()),
		convertToIntegral<unsigned long long>(*object.getMemberValue("lineNumber")->value()->get())
	);
}

std::string cMCompiler::language::convertToString(dataStructures::execution::IRuntimeValue& value)
{
	auto& string = dynamic_cast<execution::StringValue&>(value);
	return string.toString();
}

cMCompiler::language::runtime_value cMCompiler::language::convertToCollection(std::vector<runtime_value> && values, not_null<dataStructures::Type*> type, unsigned char referenceLevel)
{
	auto result = std::make_unique<execution::ArrayValue>(getCollectionTypeFor(type), type, referenceLevel);
	for (auto& v : values)
		result->push(std::move(v));
	return result;
}


cMCompiler::language::runtime_value cMCompiler::language::convertToCollection(std::vector<std::string> const& strings)
{
	auto result = std::make_unique<execution::ArrayValue>(getCollectionTypeFor(getString()), getString(), 0);
	for (auto const& s : strings)
		result->push(buildStringValue(s));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::convertCollection(std::vector<runtime_value>&& collection, gsl::not_null<dataStructures::Type*> elementType, unsigned char referenceLevel)
{
	auto result = std::make_unique<dataStructures::execution::ArrayValue>(getCollectionTypeFor(elementType), elementType, referenceLevel);
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
	do
	{
		ref = dynamic_cast<ReferenceValue*>(value.get());
		if (ref == nullptr)
			return value;
		value = ref->value()->get();
	}
	while (ref->value() != nullptr);
	std::terminate();
}

cMCompiler::dataStructures::execution::IRuntimeValue* cMCompiler::language::dereferenceOnce(not_null<dataStructures::execution::IRuntimeValue*> value)
{
	using namespace cMCompiler::dataStructures::execution;
	auto ref = dynamic_cast<ReferenceValue*>(value.get());
	if (ref == nullptr)
		return value;
	return ref->value()->get();
}
