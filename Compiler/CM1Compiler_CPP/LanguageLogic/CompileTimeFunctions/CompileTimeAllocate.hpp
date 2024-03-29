#pragma once
#include <memory>
#include <map>
#include <gsl/gsl>
#include "../../DataStructures/execution/IRuntimeValue.h"



namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> compileTimeAllocate
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, dataStructures::TypeReference> genericParameters
	);
}
