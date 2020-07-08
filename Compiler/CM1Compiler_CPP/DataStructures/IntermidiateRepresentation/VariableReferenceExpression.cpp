#include "VariableReferenceExpression.hpp"
#include "IExpressionVisitor.hpp"

void cMCompiler::dataStructures::ir::VariableReferenceExpression::emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const
{
	stream << "{@variable " << variable_->name() << "}";
}

void cMCompiler::dataStructures::ir::VariableReferenceExpression::accept(IExpressionVisitor& visitor)
{
	visitor.visit(*this);
}
