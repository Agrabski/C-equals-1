#include "SemanticModelValidationException.h"
#include "../Function.hpp"

using namespace cMCompiler::dataStructures::validation;
using namespace std::string_literals;

std::string NotAllPathsReturnAValueException::formatMessage(gsl::not_null<Function*> function, std::filesystem::path const& path)
{
	return "Non-void function does not return a value on some paths. File: '"s + path.string() + "' Function: "s + (std::string)function->qualifiedName();
}
