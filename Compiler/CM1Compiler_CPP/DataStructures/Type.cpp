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

execution::json cMCompiler::dataStructures::Type::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	std::vector<std::string> interfaceNames;
	for (auto i : implementedInterfaces_)
		interfaceNames.push_back(nameLookupFunction.get(i));
	return {
		{"name", name()},
		{"functions", execution::serializeArray(methods_, nameLookupFunction, manager)},
		{"fields", execution::serializeArray(fields_, nameLookupFunction, manager)},
		{"generic_functions", execution::serializeArray(genericFunction_, nameLookupFunction, manager)},
		{"interfaces", interfaceNames},
		{"attributes", AttributeTarget::emmitAttributes(nameLookupFunction, manager)}
	};
}
