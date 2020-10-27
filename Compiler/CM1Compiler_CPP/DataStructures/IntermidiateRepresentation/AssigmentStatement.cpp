#include "AssigmentStatement.hpp"
#include "IInstructionVisitor.hpp"

void cMCompiler::dataStructures::ir::AssigmentStatement::emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const
{
	while (indentationLevel-- > 0)
		stream << '\t';
	stream << "{@assign lvalue = ";
	lexpression_->emmit(stream, nameLookupFunction);
	stream << " rvalue = ";
	rexpression_->emmit(stream, nameLookupFunction);
}

bool cMCompiler::dataStructures::ir::AssigmentStatement::compileTimeExecutable() const noexcept
{
	return lexpression_->compileTimeExecutable() && rexpression_->compileTimeExecutable();
}

void cMCompiler::dataStructures::ir::AssigmentStatement::accept(IInstructionVisitor& visitor)
{
	visitor.visit(*this);
}
