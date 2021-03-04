#include "ReadAllFile.hpp"
#include <fstream>
#include <filesystem>
#include "../LiteralUtility.hpp"

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::compileTimeFunctions::readAllFile(std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap, std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters)
{
	using namespace std::string_literals;
	auto path = convertToString(*valueMap.at("path"s));
	std::ifstream stream = std::ifstream(path);
	std::string result((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
	return buildStringValue(result);

}
