#pragma once
#include "IInstruction.hpp"
#include "IExpression.hpp"
#include "../../LanguageLogic/BuiltInPackageBuildUtility.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IfElseStatement : public IInstruction
	{
		std::vector<std::unique_ptr<IInstruction>> if_;
		std::vector<std::unique_ptr<IInstruction>> else_;
		std::unique_ptr<IExpression> expression_;
	public:
		std::vector<not_null<IInstruction*>> ifBranch() const;
		std::vector<not_null<IInstruction*>> elseBranch() const;
		IExpression* expression() const noexcept { return expression_.get(); }
		IfElseStatement(std::unique_ptr<IExpression>&& expression, std::unique_ptr<execution::IRuntimeValue>&& pointer)
			: IInstruction(std::move(pointer))
		{
			auto const * const type = expression->evaluateType();
			if (type != language::getBool())
				//todo: better exception
				throw std::exception();
			expression_ = std::move(expression);
		}
		void pushIf(std::unique_ptr<IInstruction>&& instruction);
		void pushElse(std::unique_ptr<IInstruction>&& instruction);
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const final;
		bool compileTimeExecutable() const noexcept final;
		void accept(IInstructionVisitor& visitor) final;

	};
}
