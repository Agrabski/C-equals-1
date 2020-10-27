#pragma once
#include <memory>
#include "IInstruction.hpp"
#include "IExpression.hpp"
#include "INameGetter.hpp"
#include "../Type.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IExpression;

	class VariableDeclaration : public IInstruction
	{
		std::unique_ptr<IExpression> expression_;
		std::string variableName_;
		Type* type_;
	public:
		IExpression* expression() const noexcept { return expression_.get(); }
		std::string const& name() const noexcept { return variableName_; }
		VariableDeclaration(std::string name, std::unique_ptr<IExpression>&& exp, Type* type, std::unique_ptr<execution::IRuntimeValue>&& pointer);
		bool compileTimeExecutable() const noexcept final;
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const final;
		void accept(IInstructionVisitor& visitor) final;
	};
}

