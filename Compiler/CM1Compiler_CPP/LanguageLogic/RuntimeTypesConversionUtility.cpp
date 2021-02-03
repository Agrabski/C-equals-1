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

cMCompiler::language::runtime_value cMCompiler::language::convertToCollection(std::vector<std::string> const& strings)
{
	auto result = std::make_unique<execution::ArrayValue>(getCollectionTypeFor(getString()), getString());
	for (auto const& s : strings)
		result->push(buildStringValue(s));
	return result;
}

bool cMCompiler::language::canCastReference(gsl::not_null<dataStructures::Type*> from, gsl::not_null<dataStructures::Type*> to)
{
	if (from == to)
		return true;
	auto& interfaces = from->interfaces();
	return std::any_of(interfaces.begin(), interfaces.end(), [to](auto const& e) {return canCastReference(e, to); });
}
