#pragma once
#include "../DataStructures/Function.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> execute
	(
		gsl::not_null<dataStructures::Function*> functionDefinition,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap
	);

}
