#include "AttributeTarget.hpp"

using namespace cMCompiler::dataStructures;

AttributeInstance* AttributeTarget::appendAttribute(std::unique_ptr<AttributeInstance> attribute)
{
	auto result = attribute.get();
	attributes_.push_back(std::move(attribute));
	return result;
}


execution::json cMCompiler::dataStructures::AttributeTarget::emmitAttributes(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	//todo: do
	return execution::json();
}
