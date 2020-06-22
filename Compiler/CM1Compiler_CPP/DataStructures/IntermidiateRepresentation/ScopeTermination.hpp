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
		ScopeTermination(std::vector<Variable*>&& variables) : variablesToFinalize_(std::move(variables)) {}
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const final;
		bool compileTimeExecutable() const noexcept final { return true; }
	};
}
