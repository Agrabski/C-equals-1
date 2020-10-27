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
		std::vector<std::unique_ptr<IExpression>> variables_;
	public:
		FunctionCall(std::vector<gsl::unique_ptr<IExpression>>&& variables, Function* compiletime, Function* runtime, std::unique_ptr<execution::IRuntimeValue>&& pointer) noexcept :
			IInstruction(std::move(pointer)), runtimeFunction_(runtime), compiletimeFunction_(compiletime), variables_(std::move(variables))
		{
			assert(compiletime != nullptr || runtime != nullptr);
		}
		bool compileTimeExecutable() const noexcept final;
		Type* evaluateType() const noexcept final;
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const final;

		// Inherited via IInstruction
		virtual void accept(IInstructionVisitor& visitor) override;

		// Inherited via IExpression
		virtual void emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const override;
		virtual void accept(IExpressionVisitor& visitor) override;

		std::vector<std::unique_ptr<IExpression>>& parameters() noexcept{ return variables_; }
		Function* compileTimeFunction() const noexcept { return compiletimeFunction_; }
	};
}
