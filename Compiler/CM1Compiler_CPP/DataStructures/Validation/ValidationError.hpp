#pragma once
#include <string>

namespace cMCompiler::dataStructures::validation
{
	using ValidationCode = unsigned long;
	enum class BuiltInValidationErrors : ValidationCode
	{
		MissingTypeClassifier,
		ClassNotFinalized
	};

	ValidationCode toCode(BuiltInValidationErrors error) noexcept;

	struct ValidationError
	{
		ValidationCode code_;
		std::string message_;
	};
}
