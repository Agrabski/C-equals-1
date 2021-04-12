#include "IRuntimeValue.h"

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::IRuntimeValue::serialize(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const noexcept
{
	return {
		{"implementation_typename", typeName()},
		{"type", nameLookupFunction.get(type_)},
		{"value", emmit(nameLookupFunction, manager)},
		{"serialization_id", manager.getId(this)}
	};
}
