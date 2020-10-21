#pragma once
#include <memory>
#include "IExpression.hpp"
#include "IInstruction.hpp"

namespace cMCompiler::dataStructures::ir
{
	class AssigmentStatement : public IInstruction
	{
		std::unique_ptr<IExpression> lexpression_;
		std::unique_ptr<IExpression> rexpression_;
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const final;
		bool compileTimeExecutable() const noexcept final;
		void accept(IInstructionVisitor& visitor) final;
	public:
		gsl::not_null<IExpression*> lexpression() noexcept { return lexpression_.get(); }
		gsl::not_null<IExpression*> rexpression() noexcept { return rexpression_.get(); }
		AssigmentStatement(std::unique_ptr<IExpression>&& lexpression, std::unique_ptr<IExpression>&& rexpression) noexcept
			: lexpression_(std::move(lexpression)), rexpression_(std::move(rexpression)) {}

	};
}