#include "FunctionCall.hpp"
#include "IInstructionVisitor.hpp"
#include "IExpressionVisitor.hpp"

bool cMCompiler::dataStructures::ir::FunctionCall::compileTimeExecutable() const noexcept
{
	return compiletimeFunction_ != nullptr;
}

cMCompiler::dataStructures::Type* cMCompiler::dataStructures::ir::FunctionCall::evaluateType() const noexcept
{
	if (runtimeFunction_ != nullptr)
		return runtimeFunction_->returnType();
	return compiletimeFunction_->returnType();
}

void cMCompiler::dataStructures::ir::FunctionCall::emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const
{

	while (indentationLevel-- > 0)
		stream << '\t';
	emmit(stream, nameLookupFunction);
}

void cMCompiler::dataStructures::ir::FunctionCall::accept(IInstructionVisitor& visitor)
{
	visitor.visit(*this);
}

void cMCompiler::dataStructures::ir::FunctionCall::emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const
{
	stream << "{@function_call compile_time = " << nameLookupFunction.get(compiletimeFunction_) << " run_time = " << nameLookupFunction.get(runtimeFunction_);
	stream << " parameters = [";
	for (auto const& param : variables_)
	{
		param->emmit(stream, nameLookupFunction);
		stream << " ";
	}
	stream << "] }";
}

void cMCompiler::dataStructures::ir::FunctionCall::accept(IExpressionVisitor& visitor)
{
	visitor.visit(*this);
}
