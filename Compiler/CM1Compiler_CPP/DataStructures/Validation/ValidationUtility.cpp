#include "ValidationUtility.hpp"

using namespace cMCompiler::dataStructures::validation;

ValidationError cMCompiler::dataStructures::validation::getMissingTypeClassifier(BuiltInValidationErrors error, std::string sourceName)
{
	auto code = toCode(error);
	switch (error)
	{
	case BuiltInValidationErrors::MissingTypeClassifier:
		return { code, "Type specifier is missing! Expected class, interface or struct for: " + sourceName };
	case BuiltInValidationErrors::ClassNotFinalized:
		return { code, "Compiler did not finalize the object. Most likley its definition was not found. Missing object name: " + sourceName };
	default:
		std::terminate();
		break;
	}
}
