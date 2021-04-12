#include "Field.hpp"

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::Field::emmit(
	ir::INameGetter const& nameLookupFunction,
	ISerializationManager& manager) const
{
	return {
		{"name", name()},
		{"type", nameLookupFunction.get(type())},
		{"attributes", AttributeTarget::emmitAttributes(nameLookupFunction, manager)}
	};
}
