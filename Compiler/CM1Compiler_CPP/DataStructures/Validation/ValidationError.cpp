#include "ValidationError.hpp"

cMCompiler::dataStructures::validation::ValidationCode cMCompiler::dataStructures::validation::toCode(BuiltInValidationErrors error) noexcept
{
	return static_cast<ValidationCode>(error);
}
