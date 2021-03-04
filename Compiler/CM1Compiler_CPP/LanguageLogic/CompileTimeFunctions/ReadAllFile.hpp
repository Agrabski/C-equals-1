#pragma once
#include <memory>
#include <map>
#include <string>
#include <gsl.h>
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/IRuntimeValue.h"


namespace cMCompiler::language::compileTimeFunctions
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> readAllFile
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters
	);
}