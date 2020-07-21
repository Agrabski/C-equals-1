#pragma once
#include <memory>
#include <map>
#include <gsl.h>
#include "../../DataStructures/execution/IRuntimeValue.h"



namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> print
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters
	);
}