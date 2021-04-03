#include "LiteralUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::language;

std::unique_ptr<execution::IntegerValue> cMCompiler::language::buildIntegerValue(dataStructures::Type* ofType)
{
	if (ofType == getUsize() || ofType == nullptr)
		return std::make_unique<execution::IntegerValue>(8, false, TypeReference{ getUsize(), 0 });
	std::terminate(); // todo: handle custom integer types
}

std::unique_ptr<cMCompiler::dataStructures::execution::IntegerValue> cMCompiler::language::buildIntegerValue(dataStructures::Type* ofType, dataStructures::execution::usize value)
{
	return buildIntegerValue(ofType,
		(dataStructures::execution::number_component*)&value,
		sizeof(decltype(value)) / sizeof(dataStructures::execution::number_component));
}

std::unique_ptr<execution::IntegerValue> cMCompiler::language::buildIntegerValue(dataStructures::Type* ofType, dataStructures::execution::number_component* value, size_t valueSize)
{
	auto result = buildIntegerValue(ofType);
	result->setValue(value, valueSize);
	return result;
}

std::unique_ptr<execution::StringValue> cMCompiler::language::buildStringValue()
{
	auto string = getDefaultPackage()->rootNamespace()->get<Type>("string");
	return std::make_unique<execution::StringValue>(TypeReference{ string, 0 });
}

std::unique_ptr<execution::StringValue> cMCompiler::language::buildStringValue(std::string const& value)
{
	auto result = buildStringValue();
	result->setValue(value);
	return result;
}

std::unique_ptr<cMCompiler::dataStructures::execution::BooleanValue> cMCompiler::language::buildBooleanValue(bool value)
{
	auto result = std::make_unique<execution::BooleanValue>(TypeReference{ getBool(), 0 });
	result->value(value);
	return result;
}

std::unique_ptr<cMCompiler::dataStructures::execution::IntegerValue> cMCompiler::language::buildCharValue(char value)
{
	return buildIntegerValue(getChar(), value);
}
