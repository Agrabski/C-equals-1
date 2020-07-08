#include "ScopeTermination.hpp"
#include "IInstructionVisitor.hpp"

void cMCompiler::dataStructures::ir::ScopeTermination::emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const
{
	for (auto i = 0U; i < indentationLevel; i++)
		stream << "\t";
	stream << "{@finalize [";
	for (auto var : variablesToFinalize_)
		stream << var->name() << " ";
	stream << "] }";
}

void cMCompiler::dataStructures::ir::ScopeTermination::accept(IInstructionVisitor& visitor)
{
	visitor.visit(*this);
}
