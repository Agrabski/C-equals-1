#pragma once
#include "IExpression.hpp"
#include "../Variable.hpp"

namespace cMCompiler::dataStructures::ir
{
	class VariableReferenceExpression : public IExpression
	{
		Variable* variable_;
	public:
		VariableReferenceExpression(Variable* variable) noexcept : variable_(variable) {}
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const final;
		bool compileTimeExecutable() const noexcept final { return true; }
		Type* evaluateType() const noexcept final { return variable_->type(); }
	};
}
