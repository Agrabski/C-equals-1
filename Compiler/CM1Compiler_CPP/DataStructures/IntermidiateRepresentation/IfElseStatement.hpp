#pragma once
#include "IInstruction.hpp"
#include "IExpression.hpp"
#include "../../LanguageLogic/BuiltInPackageBuildUtility.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IfElseStatement: public IInstruction
	{
		std::vector<std::unique_ptr<IInstruction>> if_;
		std::vector<std::unique_ptr<IInstruction>> else_;
		std::unique_ptr<IExpression> expression_;
	public:
		IfElseStatement(std::unique_ptr<IExpression>&& expression)
		{
			if (expression->evaluateType() != language::getBool())
				//todo: better exception
				throw std::exception();
			expression_ = std::move(expression);
		}
		void pushIf(std::unique_ptr<IInstruction>&& instruction);
		void pushElse(std::unique_ptr<IInstruction>&& instruction);
		void emmit(std::ostream& stream, std::function<std::string(dataStructures::Type*)> const& nameLookupFunction, unsigned int indentationLevel) const final;
		bool compileTimeExecutable() const noexcept final;
	};
}
