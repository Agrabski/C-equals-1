#pragma once
#include "IInstruction.hpp"
#include "IExpression.hpp"
#include "../Function.hpp"
#include "ExecutionContext.hpp"

namespace cMCompiler::dataStructures::ir
{
	class FunctionCall : public IInstruction, public IExpression
	{
		Function* runtimeFunction_;
		Function* compiletimeFunction_;
		std::vector<gsl::not_null<Variable*>> variables_;
	public:
		FunctionCall(std::vector<gsl::not_null<Variable*>> variables, Function* compiletime, Function* runtime) :
			runtimeFunction_(runtime), compiletimeFunction_(compiletime), variables_(variables) {}
		bool compileTimeExecutable() const noexcept final;
		Type* evaluateType() const noexcept final;
		virtual void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const override;
	};
}
