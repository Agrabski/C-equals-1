#include "INamedObject.hpp"
#include "Validation/ValidationUtility.hpp"

using namespace cMCompiler::dataStructures;

QualifiedName INamedObject::qualifiedName() const
{
	if (parent() != nullptr)
		return parent()->qualifiedName() + name_;
	return QualifiedName();
}

std::vector<validation::ValidationError> cMCompiler::dataStructures::INamedObject::validate() const
{
	auto result = validateContent();
	if (state_ != ObjectState::Finalized)
		result.push_back(validation::getMissingTypeClassifier(validation::BuiltInValidationErrors::ClassNotFinalized, (std::string)qualifiedName()));
	return result;
}
