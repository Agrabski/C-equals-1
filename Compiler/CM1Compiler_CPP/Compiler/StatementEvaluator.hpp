#pragma once
#include "../LanguageLogic/runtime_values.hpp"
#include "ExpressionEvaluator.hpp"

namespace cMCompiler::compiler
{
	class StatementEvaluator
	{
		dataStructures::Function& definition_;
		ExpressionEvaluator& ev_;

		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>& variables_;
		// Inherited via IInstructionVisitor
		void call(language::runtime_value& instruction);
	public:
		void evaluate(language::runtime_value& instruction);
		StatementEvaluator
		(
			dataStructures::Function& definition,
			ExpressionEvaluator& ev,
			std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>& variables

		) noexcept : definition_(definition), ev_(ev), variables_(variables)
		{}
	};
}
