#include "VariableReferenceExpression.hpp"

void cMCompiler::dataStructures::ir::VariableReferenceExpression::emmit(std::ostream& stream, std::function<QualifiedName(Type*)> nameLookupFunction) const
{
	stream << "{@variable " << variable_->name() << "}";
}
