#include "VariableDeclaration.hpp"
#include "IInstructionVisitor.hpp"

cMCompiler::dataStructures::ir::VariableDeclaration::VariableDeclaration(std::string name, std::unique_ptr<IExpression>&& exp, Type* type, std::unique_ptr<execution::IRuntimeValue>&& pointer) :
	IInstruction(std::move(pointer)), variableName_(name), expression_(std::move(exp)), type_(type)
{
	if (expression_ == nullptr && type == nullptr)
		throw std::exception(); //todo: better exception
	if (type_ == nullptr)
		type_ = expression_->evaluateType();
}

bool cMCompiler::dataStructures::ir::VariableDeclaration::compileTimeExecutable() const noexcept
{
	return expression_->compileTimeExecutable();
}

void cMCompiler::dataStructures::ir::VariableDeclaration::emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const
{
	for (auto i = 0U; i < indentationLevel; i++)
		stream << "\t";
	stream << "{@declare " << variableName_;
	stream << " | " << nameLookupFunction.get(type_);
	stream << ", expression = ";
	if (expression_ != nullptr)
		expression_->emmit(stream, nameLookupFunction);
	else
		stream << "{}";
	stream << "}";
}

void cMCompiler::dataStructures::ir::VariableDeclaration::accept(IInstructionVisitor& visitor)
{
	visitor.visit(*this);
}
