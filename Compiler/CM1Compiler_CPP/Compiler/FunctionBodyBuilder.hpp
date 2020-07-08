#pragma once
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../DataStructures/IntermidiateRepresentation/IInstruction.hpp"
#include "../DataStructures/Function.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "ExpressionBuilder.hpp"

namespace cMCompiler::compiler
{
	class FunctionBodyBuilder : public CMinusEqualsMinus1Revision0BaseVisitor
	{
		using instruction_pointer = std::unique_ptr<dataStructures::ir::IInstruction>;
		dataStructures::Function* function_;
		language::NameResolver& nr_;
		language::NameResolutionContext& context_;
		std::vector<std::vector<dataStructures::Variable*>> variables_;
		std::vector<std::function<void(instruction_pointer&&)>> instructionAppenders;
		void enterScope();
		[[nodiscard]]
		std::unique_ptr< cMCompiler::dataStructures::ir::ScopeTermination>  leaveScope();
		ExpressionBuilder getBuilder();

		antlrcpp::Any visitVariableDeclarationStatement(CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* ctx) final;
		antlrcpp::Any visitFunctionBody(CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* ctx) final;
		antlrcpp::Any visitIfStatement(CMinusEqualsMinus1Revision0Parser::IfStatementContext* ctx) final;
		antlrcpp::Any visitFunctionCall(CMinusEqualsMinus1Revision0Parser::FunctionCallContext* ctx) final;
		antlrcpp::Any visitAssigmentStatement(CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* ctx) final;
	public:
		FunctionBodyBuilder(dataStructures::Function* function, language::NameResolver& nr, language::NameResolutionContext& context) noexcept :
			function_(function), nr_(nr), context_(context) {}

	};
}
