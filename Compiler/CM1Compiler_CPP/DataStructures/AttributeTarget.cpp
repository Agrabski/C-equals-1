#include "AttributeTarget.hpp"

using namespace cMCompiler::dataStructures;

AttributeInstance* AttributeTarget::appendAttribute(std::unique_ptr<AttributeInstance> attribute)
{
	auto result = attribute.get();
	attributes_.push_back(std::move(attribute));
	return result;
}

std::vector<AttributeInstance*> cMCompiler::dataStructures::AttributeTarget::attributes()
{
	auto result = std::vector<AttributeInstance*>();
	for (auto& att : attributes_)
		result.push_back(att.get());
	return result;
}
