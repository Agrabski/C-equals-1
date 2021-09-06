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
std::vector<INamedObject*> cMCompiler::dataStructures::Type::children() noexcept
{
	auto result = std::vector<INamedObject*>();
	for (auto& c : methods_)
		result.push_back(c.get());
	for (auto& c : fields_)
		result.push_back(c.get());
	for (auto& c : genericFunction_)
		result.push_back(c.get());


	return result;
}

Field* cMCompiler::dataStructures::Type::appendField(std::string const& name, TypeReference type)
{
	fields_.push_back(std::make_unique<Field>(name, type, this, package()));
	auto result = fields_.back().get();
	if (result->type().type != nullptr && result->type().type->metadata().hasFlag(TypeFlags::ExcludeAtRuntime))
		metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	return result;
}

TypeFlags cMCompiler::dataStructures::operator|(TypeFlags lhs, TypeFlags rhs)
{
	return static_cast<TypeFlags>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs));
}

TypeFlags cMCompiler::dataStructures::operator&(TypeFlags lhs, TypeFlags rhs)
{
	return static_cast<TypeFlags>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs));
}
