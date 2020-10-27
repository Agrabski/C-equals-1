#pragma once
#include "IInstruction.hpp"
#include "IExpression.hpp"
#include "../Function.hpp"
#include "../Variable.hpp"

namespace cMCompiler::dataStructures
{
	class Variable;
}

namespace cMCompiler::dataStructures::ir
{
	class ScopeTermination : public IInstruction
	{
		std::vector<Variable*> variablesToFinalize_;
	public:
		std::vector<Variable*> const& variablesToFinalize() const noexcept { return variablesToFinalize_; }
		ScopeTermination(std::vector<Variable*>&& variables, std::unique_ptr<execution::IRuntimeValue>&& pointer) noexcept :
			IInstruction(std::move(pointer)), variablesToFinalize_(std::move(variables)) {}
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const final;
		bool compileTimeExecutable() const noexcept final { return true; }
		void accept(IInstructionVisitor& visitor) final;
	};
}
