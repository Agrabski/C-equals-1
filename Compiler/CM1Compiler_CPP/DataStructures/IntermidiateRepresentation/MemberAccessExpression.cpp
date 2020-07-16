#include "MemberAccessExpression.hpp"
#include "IExpressionVisitor.hpp"

void cMCompiler::dataStructures::ir::MemberAccessExpression::emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const
{
	stream << "{@member_access expression = ";
	initialExpression_->emmit(stream, nameLookupFunction);
	stream << " path = [ ";
	for (auto const& s : memberChain_)
		stream << s << " ";
	stream << " ] }";
}

bool cMCompiler::dataStructures::ir::MemberAccessExpression::compileTimeExecutable() const noexcept
{
	return initialExpression_->compileTimeExecutable();
}

cMCompiler::dataStructures::Type* cMCompiler::dataStructures::ir::MemberAccessExpression::evaluateType() const noexcept
{
	auto result = initialExpression()->evaluateType();
	for (auto const s : memberChain_)
	{
		auto fields = result->fields();
		result = (*std::find_if(fields.begin(), fields.end(), [&](const auto& e) {return e->name() == s; }))->type();
	}
	return result;
}

void cMCompiler::dataStructures::ir::MemberAccessExpression::accept(IExpressionVisitor& visitor)
{
	visitor.visit(*this);
}
