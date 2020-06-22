#pragma once
#include "ValidationError.hpp"

namespace cMCompiler::dataStructures::validation
{
	ValidationError getMissingTypeClassifier(BuiltInValidationErrors error, std::string sourceName);
}
