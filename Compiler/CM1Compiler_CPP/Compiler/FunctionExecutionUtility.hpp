#pragma once
#include "../DataStructures/Function.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::compiler
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> execute
	(
		gsl::not_null<dataStructures::Function*> functionDefinition,
		std::map<std::string, dataStructures::execution::IRuntimeValue*> valueMap
	);

}
