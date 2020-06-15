#include "AttributeUtility.hpp"

using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;

std::vector<std::unique_ptr<AttributeInstance>> getAttributes(not_null<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext*> attributeSequence, NameResolutionContext& context, NameResolver& nr)
{
	auto result = std::vector<std::unique_ptr<AttributeInstance>>();
	for (auto attribute : attributeSequence->attribute())
	{
		not_null functionCall = attribute->functionCall();
		//todo: add error handling
		auto attribute = nr.resolve<Attribute>(functionCall->Identifier()->getText(), context);
	}
	return result;
}
