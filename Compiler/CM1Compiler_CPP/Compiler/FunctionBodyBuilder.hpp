#pragma once
#include <filesystem>
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../DataStructures/Function.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "ExpressionBuilder.hpp"

namespace cMCompiler::compiler
{
	class FunctionBodyBuilder : public CMinusEqualsMinus1Revision0BaseVisitor
	{
		std::string decorateTemporary(not_null<antlr4::tree::ParseTree*>tree, int index);
		std::string decorateRangeLoopEndVariableName(std::string const& original);
		using instruction_pointer = std::unique_ptr<dataStructures::execution::IRuntimeValue>;
		dataStructures::Function* function_;
		language::NameResolver& nr_;
		language::NameResolutionContext& context_;
		std::vector<std::vector<gsl::not_null<dataStructures::Variable*>>> variables_;
		std::vector<std::function<void(instruction_pointer&&)>> instructionAppenders;
		std::vector<instruction_pointer> parents_;
		void enterScope(instruction_pointer& currentInstruction);
		[[nodiscard]]
		cMCompiler::language::runtime_value leaveScope(unsigned long long line);
		ExpressionBuilder getBuilder();
		std::filesystem::path filePath_;

		void buildWhileLoop(
			language::runtime_value&& expression,
			not_null<antlr4::tree::ParseTree*> body,
			std::function<void()> actionInNewScope = {},
			std::function<void()> actionAtEndOfNewScope = {}
		);

		void buildForLoop(
			std::string const& variableName,
			std::function<language::runtime_value()> variableInitialisationExpressionFactory,
			std::function<language::runtime_value(not_null<dataStructures::Variable*>)> testExpressionFactory,
			std::function<void(not_null<dataStructures::Variable*>)> postExpressionFactory,
			not_null<antlr4::tree::ParseTree*> body,
			std::function<void(not_null<dataStructures::Variable*>)> actionInNewScope = {}
		);

		void buildForRangeLoop(
			std::string const& variableName,
			language::runtime_value&& expression,
			not_null<antlr4::tree::ParseTree*> body);

		language::runtime_value getReferenceToParent();

		antlrcpp::Any visitVariableDeclarationStatement(CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* ctx) final;
		antlrcpp::Any visitFunctionBody(CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* ctx) final;
		antlrcpp::Any visitIfStatement(CMinusEqualsMinus1Revision0Parser::IfStatementContext* ctx) final;
		antlrcpp::Any visitRangeForStatement(CMinusEqualsMinus1Revision0Parser::RangeForStatementContext* ctx) final;
		antlrcpp::Any visitFunctionCallStatement(CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext* ctx) final;
		antlrcpp::Any visitAssigmentStatement(CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* ctx) final;
		antlrcpp::Any visitReturnStatement(CMinusEqualsMinus1Revision0Parser::ReturnStatementContext* ctx) final;
		antlrcpp::Any visitWhileStatement(CMinusEqualsMinus1Revision0Parser::WhileStatementContext* ctx) final;
	public:
		FunctionBodyBuilder(dataStructures::Function* function, language::NameResolver& nr, language::NameResolutionContext& context, std::filesystem::path const& f) noexcept :
			filePath_(f), function_(function), nr_(nr), context_(context) {}

	};
}
