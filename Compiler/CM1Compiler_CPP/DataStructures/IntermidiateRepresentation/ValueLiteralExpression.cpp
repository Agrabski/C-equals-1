#include "ValueLiteralExpression.hpp"

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
