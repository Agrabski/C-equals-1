#include "Print.hpp"
#include <iostream>

using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> cMCompiler::language::compileTimeFunctions::print(std::map<std::string, dataStructures::execution::IRuntimeValue*> valueMap)
{
	if (valueMap.size() != 1)
		throw std::exception(); //todo: better exception
	std::cout << valueMap["value"]->toString();
	return nullptr;
}
