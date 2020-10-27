#include "RuntimeTypesConversionUtility.hpp"
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
