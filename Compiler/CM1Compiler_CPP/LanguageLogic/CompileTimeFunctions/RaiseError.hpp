#pragma once
#include <memory>
#include <map>
#include <string>
#include <gsl/gsl>
#include "../../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language::compileTimeFunctions
{
	/// fn raiseError(pointer: pointerToSource&, message: string&, code: usize);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> raiseError
	(
		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
		std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters
	);
}
