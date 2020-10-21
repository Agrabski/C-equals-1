#pragma once
#include "IExpression.hpp"

namespace cMCompiler::dataStructures::ir
{
	class MemberAccessExpression : public IExpression
	{
		std::unique_ptr<IExpression> initialExpression_;
		std::vector<std::string> memberChain_;
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const final;
		bool compileTimeExecutable() const noexcept final;
		Type* evaluateType() const noexcept final;
		void accept(IExpressionVisitor& visitor) final;
	public:
		MemberAccessExpression(std::unique_ptr<IExpression>&& initial, std::vector<std::string> members) :
			initialExpression_(std::move(initial)), memberChain_(members) {}
		IExpression* initialExpression() const noexcept { return initialExpression_.get(); }
		std::vector<std::string> const& memberChain() const noexcept { return memberChain_; }
	};
}
