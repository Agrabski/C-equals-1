#include "Type.hpp"
#include "Validation/ValidationUtility.hpp"

using namespace cMCompiler::dataStructures;

std::vector<validation::ValidationError> cMCompiler::dataStructures::Type::validateContent() const
{
	auto result = std::vector<validation::ValidationError>();
	if (typeClassification_ == TypeClassifier::None)
		result.push_back(validation::getMissingTypeClassifier(validation::BuiltInValidationErrors::MissingTypeClassifier, (std::string)qualifiedName()));
	return result;
}
