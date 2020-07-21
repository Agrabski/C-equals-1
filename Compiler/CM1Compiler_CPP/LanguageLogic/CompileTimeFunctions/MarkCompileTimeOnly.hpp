#pragma once
#include <memory>
#include <map>
#include "../../DataStructures/Type.hpp"
#include "../../DataStructures/execution/IRuntimeValue.h"


namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> markCompileTimeOnly
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, not_null<dataStructures::Type*>> genericParameters

	);
}
