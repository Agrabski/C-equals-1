#include "RaiseError.hpp"
#include "../CompilerInterface.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> cMCompiler::language::compileTimeFunctions::raiseError(
	std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
	std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters)
{
	using namespace std::string_literals;
	auto message = convertToString(*valueMap.at("message"s));
	auto code = convertToIntegral<unsigned long long>(*valueMap.at("code"s));
	auto pointer = convertToSourcePointer(*valueMap.at("pointerToSource"s));
	CompilerInterface::getInstance().raiseError(message, pointer, code);
	return std::unique_ptr<IRuntimeValue>();
}
