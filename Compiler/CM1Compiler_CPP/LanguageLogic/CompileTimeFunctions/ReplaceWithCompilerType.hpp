#pragma once
#include <map>
#include "../../DataStructures/execution/IRuntimeValue.h"
#include "../../DataStructures/Type.hpp"

namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> replaceWithCompilerType
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, not_null<dataStructures::Type*>> genericParameters
	);
}