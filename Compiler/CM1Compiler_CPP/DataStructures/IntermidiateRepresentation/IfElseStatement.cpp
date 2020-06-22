#include "IfElseStatement.hpp"

void indent(std::ostream& stream, unsigned int level)
{
	for (auto i = 0U; i < level; i++)
		stream << "\t";
}

void cMCompiler::dataStructures::ir::IfElseStatement::pushIf(std::unique_ptr<IInstruction>&& instruction)
{
	if_.push_back(std::move(instruction));
}

void cMCompiler::dataStructures::ir::IfElseStatement::pushElse(std::unique_ptr<IInstruction>&& instruction)
{
	else_.push_back(std::move(instruction));
}

void cMCompiler::dataStructures::ir::IfElseStatement::emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const
{
	indent(stream, indentationLevel);
	stream << "{@if expression =";
	expression_->emmit(stream, nameLookupFunction);
	stream << "\r\n";
	indent(stream, indentationLevel + 1);
	stream << "then = \r\n";
	indent(stream, indentationLevel + 1);
	stream << "[\r\n";
	for (auto& instruction : if_)
	{
		instruction->emmit(stream, nameLookupFunction, indentationLevel + 2);
		stream << "\r\n";
	}
	indent(stream, indentationLevel + 1);
	stream << "]\r\n";
	indent(stream, indentationLevel + 1);
	stream << "else =\r\n";
	indent(stream, indentationLevel + 1);
	stream<<"[\r\n";
	for (auto& instruction : else_)
	{
		instruction->emmit(stream, nameLookupFunction, indentationLevel + 2);
		stream << "\r\n";
	}
	indent(stream, indentationLevel + 1);
	stream << "]\r\n";
	indent(stream, indentationLevel);
	stream << "}";
}

bool cMCompiler::dataStructures::ir::IfElseStatement::compileTimeExecutable() const noexcept
{
	if (!expression_->compileTimeExecutable())
		return false;
	for (auto const& exp : if_)
		if (!exp->compileTimeExecutable())
			return false;
	for (auto const& exp : else_)
		if (!exp->compileTimeExecutable())
			return false;
	return true;
}
