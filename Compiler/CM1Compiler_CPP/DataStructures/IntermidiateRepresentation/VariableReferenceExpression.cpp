#include "VariableReferenceExpression.hpp"

void cMCompiler::dataStructures::ir::VariableReferenceExpression::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@variable " << variable_->name() << "}";
}
