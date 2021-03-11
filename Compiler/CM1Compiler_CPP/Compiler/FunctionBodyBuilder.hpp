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

		language::runtime_value getReferenceToParent();

		antlrcpp::Any visitVariableDeclarationStatement(CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* ctx) final;
		antlrcpp::Any visitFunctionBody(CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* ctx) final;
		antlrcpp::Any visitIfStatement(CMinusEqualsMinus1Revision0Parser::IfStatementContext* ctx) final;
		antlrcpp::Any visitFunctionCallStatement(CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext* ctx) final;
		antlrcpp::Any visitAssigmentStatement(CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* ctx) final;
	public:
		FunctionBodyBuilder(dataStructures::Function* function, language::NameResolver& nr, language::NameResolutionContext& context, std::filesystem::path const& f) noexcept :
			filePath_(f), function_(function), nr_(nr), context_(context) {}

	};
}
