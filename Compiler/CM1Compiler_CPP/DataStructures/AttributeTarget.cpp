#include "AttributeTarget.hpp"

using namespace cMCompiler::dataStructures;

AttributeInstance* AttributeTarget::appendAttribute(std::unique_ptr<AttributeInstance> attribute)
{
	auto result = attribute.get();
	attributes_.push_back(std::move(attribute));
	return result;
}

std::vector<gsl::not_null<AttributeInstance*>> cMCompiler::dataStructures::AttributeTarget::attributes()
{
	auto result = std::vector<gsl::not_null<AttributeInstance*>>();
	for (auto& att : attributes_)
		result.push_back(att.get());
	return result;
}

execution::json cMCompiler::dataStructures::AttributeTarget::emmitAttributes(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	//todo: do
	return execution::json();
}
