#include "Variable.hpp"

using namespace cMCompiler::dataStructures;

TypeReference cMCompiler::dataStructures::Variable::type() const noexcept
{
	return type_;
}

execution::json cMCompiler::dataStructures::Variable::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		{"name", name()},
		{"type", nameLookupFunction.get(type_)},
		{"attributes", AttributeTarget::emmitAttributes(nameLookupFunction, manager)}//,
		//{"scope_begin", scopeBegin_->serialize(nameLookupFunction, manager)},
		//{"scope_end", scopeEnd_->serialize(nameLookupFunction, manager)}
	};
	//todo: do
}
