#pragma once
#include <map>
#include "../../DataStructures/execution/IRuntimeValue.h"



namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> replaceWithCompilerType
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap
	);
}