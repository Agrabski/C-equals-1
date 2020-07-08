#include "ValueLiteralExpression.hpp"
#include "IExpressionVisitor.hpp"

using namespace cMCompiler::dataStructures;

void cMCompiler::dataStructures::ir::ValueLiteralExpression::emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const
{
	stream << "{@literal ";
	value_->emmit(stream, nameLookupFunction);
	stream << "}";
}

bool cMCompiler::dataStructures::ir::ValueLiteralExpression::compileTimeExecutable() const noexcept
{
	return true;
}

Type* cMCompiler::dataStructures::ir::ValueLiteralExpression::evaluateType() const noexcept
{
	return value_->type();
}

void cMCompiler::dataStructures::ir::ValueLiteralExpression::accept(IExpressionVisitor& visitor)
{
	visitor.visit(*this);
}

std::unique_ptr<execution::IRuntimeValue> cMCompiler::dataStructures::ir::ValueLiteralExpression::value()
{
	return value_->copy();
}
