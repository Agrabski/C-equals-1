#include "Print.hpp"
#include <iostream>

using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> cMCompiler::language::compileTimeFunctions::print(
	std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap
)
{
	if (valueMap.size() != 1)
		throw std::exception(); //todo: better exception
	std::cout << valueMap["value"]->toString() << std::endl;
	return nullptr;
}
