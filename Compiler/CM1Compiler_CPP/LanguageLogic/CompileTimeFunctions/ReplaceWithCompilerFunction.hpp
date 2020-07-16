#pragma once
#include <memory>
#include <map>
#include "../../DataStructures/execution/IRuntimeValue.h"



namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> replaceWithCompilerFunction
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap
	);
}