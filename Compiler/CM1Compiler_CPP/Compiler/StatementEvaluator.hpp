#pragma once
#include "../DataStructures/IntermidiateRepresentation/IInstructionVisitor.hpp"
#include "../LanguageLogic/runtime_values.hpp"
#include "ExpressionEvaluator.hpp"

namespace cMCompiler::compiler
{
	class StatementEvaluator : dataStructures::ir::IInstructionVisitor
	{
		dataStructures::Function& definition_;
		ExpressionEvaluator& ev_;
		language::NameResolver& resolver_;
		language::NameResolutionContext& context_;

		std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>& variables_;
		// Inherited via IInstructionVisitor
		void visit(dataStructures::ir::FunctionCall&) final;
		void visit(dataStructures::ir::VariableDeclaration&) final;
		void visit(dataStructures::ir::IfElseStatement&) final;
		void visit(dataStructures::ir::ScopeTermination&) final;
		void visit(dataStructures::ir::AssigmentStatement&) final;
		void call(language::runtime_value& instruction);
	public:
		void visit(dataStructures::ir::IInstruction& instruction);
		void evaluate(language::runtime_value& instruction);
		StatementEvaluator
		(
			dataStructures::Function& definition,
			ExpressionEvaluator& ev,
			std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>& variables,
			language::NameResolver& resolver,
			language::NameResolutionContext& context

		) noexcept : definition_(definition), ev_(ev), variables_(variables_), resolver_(resolver), context_(context)
		{}
	};
}
