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

void cMCompiler::dataStructures::ir::FunctionCall::accept(IInstructionVisitor& visitor)
{
	visitor.visit(*this);
}

void cMCompiler::dataStructures::ir::FunctionCall::accept(IExpressionVisitor& visitor)
{
	visitor.visit(*this);
}
