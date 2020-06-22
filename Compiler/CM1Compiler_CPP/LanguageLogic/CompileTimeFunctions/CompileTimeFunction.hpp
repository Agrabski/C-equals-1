#pragma once
#include <functional>
#include "../../DataStructures/Function.hpp"
#include "../../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language::compileTimeFunctions
{
	using compileTimeFunction =
		std::function <
		std::unique_ptr<dataStructures::execution::IRuntimeValue>
		(
			std::map<std::string, dataStructures::execution::IRuntimeValue*> valueMap
		)
		>;
}