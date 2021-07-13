#pragma once
#include <memory>
#include <map>
#include <iostream>
#include <gsl.h>
#include "../../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language::compileTimeFunctions
{

	std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> boobs(
		std::map<std::string, std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue>>&& valueMap, std::map<std::string, gsl::not_null<cMCompiler::dataStructures::Type*>> genericParameters)
	{
		std::cout << "You called a function named boobs. I don't know what did you expect... Heres some boobs: (.Y.)" << std::endl;
		return nullptr;
	}
}