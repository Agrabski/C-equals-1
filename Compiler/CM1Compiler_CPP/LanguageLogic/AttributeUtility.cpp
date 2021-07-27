#include "AttributeUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;

std::vector<std::unique_ptr<AttributeInstance>> getAttributes(not_null<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext*> attributeSequence, NameResolutionContext& context, NameResolver& nr)
{
	auto result = std::vector<std::unique_ptr<AttributeInstance>>();
	for (auto attribute : attributeSequence->attribute())
	{
		not_null functionCall = attribute->functionCall();
		//todo: add error handling
		auto attribute = nr.resolve<Attribute>(functionCall->identifier()->getText(), context);
	}
	return result;
}

AttributeInstance* cMCompiler::language::getAttribute(AttributeTarget& target, Attribute* attribute)
{
	auto attributes = target.attributes();
	auto result = std::find_if(attributes.begin(), attributes.end(), [&](const auto e) {return e->basedOn() == attribute; });
	if (result != attributes.end())
		return *result;
	return nullptr;
}

std::function<bool(not_null<AttributeInstance*>att)> cMCompiler::language::getIsDescribedByTypePredicate(dataStructures::TypeReference t)
{
	auto type = t.type;
	return [type](not_null<AttributeInstance*> attribute)
	{
		return attribute->basedOn()->describingType() == type;
	};
}
