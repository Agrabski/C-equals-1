#include "FunctionCall.hpp"

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
