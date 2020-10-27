#include "FunctionBodyBuilder.hpp"
#include "../DataStructures/IntermidiateRepresentation/VariableDeclaration.hpp"
#include "ExpressionBuilder.hpp"
#include "../DataStructures/IntermidiateRepresentation/IfElseStatement.hpp"
#include "../DataStructures/IntermidiateRepresentation/AssigmentStatement.hpp"
#include "../DataStructures/IntermidiateRepresentation/FunctionCall.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"

void cMCompiler::compiler::FunctionBodyBuilder::enterScope()
{
	variables_.push_back({});
}

[[nodiscard]]
std::unique_ptr< cMCompiler::dataStructures::ir::ScopeTermination> cMCompiler::compiler::FunctionBodyBuilder::leaveScope(unsigned long long line)
{
	auto instruction = std::make_unique<dataStructures::ir::ScopeTermination>(
		std::move(variables_.back()),
		language::buildPointerToSource(filePath_.filename().string(), line)
		);
	language::supplyValueTo(instruction.get());
	variables_.pop_back();
	return instruction;
}

cMCompiler::compiler::ExpressionBuilder cMCompiler::compiler::FunctionBodyBuilder::getBuilder()
{
	return ExpressionBuilder([this](auto const& e) -> dataStructures::Variable*
	{
		auto varFinder = [&](const auto& v) noexcept {return v->name() == e; };
		for (auto& scope : variables_)
		{
			auto var = std::find_if(scope.begin(), scope.end(), varFinder);
			if (var != scope.end())
				return *var;
		}
		auto const& params = function_->parameters();
		auto var = std::find_if(params.begin(), params.end(), varFinder);
		if (var != params.end())
			return *var;
		return nullptr;
	});
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitVariableDeclarationStatement(CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* ctx)
{
	//todo: attributes
	std::unique_ptr<dataStructures::ir::IExpression> expression;
	dataStructures::Type* type = nullptr;
	auto typeAnnotationPresent = (ctx->Identifier().size() != 1);
	if (typeAnnotationPresent)
		type = nr_.resolve<dataStructures::Type>(ctx->Identifier(1)->getText(), context_);
	if (!typeAnnotationPresent || ctx->functionCallParameter())
		expression = getBuilder().buildExpression(ctx->functionCallParameter());

	auto name = ctx->Identifier(0)->getText();

	auto instruction = std::make_unique<dataStructures::ir::VariableDeclaration>(
		name,
		std::move(expression),
		type,
		language::buildPointerToSource(filePath_.filename().string(), ctx->Identifier(0)->getSymbol()->getLine())
		);
	not_null variable = function_->appendLocalVariable(name, type);
	variable->provideScope(instruction.get());
	language::supplyValueTo(instruction.get());
	instructionAppenders.back()(std::move(instruction));
	variables_.back().push_back(variable);
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitFunctionBody(CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* ctx)
{
	enterScope();
	instructionAppenders.push_back([&](auto&& e) {function_->pushInstruction(std::move(e)); });
	auto r = visitChildren(ctx);
	instructionAppenders.back()(leaveScope(ctx->CloseBracket()->getSymbol()->getLine()));
	instructionAppenders.pop_back();
	return r;
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitIfStatement(CMinusEqualsMinus1Revision0Parser::IfStatementContext* ctx)
{
	auto expression = getBuilder().buildExpression(ctx->logicalExpression());
	auto conditional = std::make_unique<dataStructures::ir::IfElseStatement>(
		std::move(expression),
		language::buildPointerToSource(filePath_.filename().string(), ctx->compoundStatement(0)->OpenBracket()->getSymbol()->getLine())
		);
	enterScope();
	instructionAppenders.push_back([&](auto&& e) {conditional->pushIf(std::move(e)); });
	ctx->compoundStatement(0)->accept(this);
	conditional->pushIf(leaveScope(ctx->ParamOpen()->getSymbol()->getLine()));
	instructionAppenders.pop_back();

	if (ctx->compoundStatement(1) != nullptr)
	{
		enterScope();
		instructionAppenders.push_back([&](auto&& e) {conditional->pushElse(std::move(e)); });
		ctx->compoundStatement(1)->accept(this);
		conditional->pushElse(leaveScope(ctx->compoundStatement(1)->CloseBracket()->getSymbol()->getLine()));
		instructionAppenders.pop_back();
	}
	language::supplyValueTo(conditional.get());
	instructionAppenders.back()(std::move(conditional));

	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitFunctionCall(CMinusEqualsMinus1Revision0Parser::FunctionCallContext* ctx)
{
	auto functions = nr_.resolveOverloadSet(ctx->Identifier()->getText(), context_);
	auto params = std::vector<std::unique_ptr<dataStructures::ir::IExpression>>();
	for (auto parameter : ctx->functionCallParameter())
		params.push_back(getBuilder().buildExpression(parameter));
	auto f = language::resolveOverload(functions, params); //todo: resolve for runtime and compile-time
	auto instruction = std::make_unique<dataStructures::ir::FunctionCall>(
		std::move(params),
		f,
		f,
		language::buildPointerToSource(filePath_.filename().string(), ctx->Identifier()->getSymbol()->getLine())
		);
	language::supplyValueTo(instruction.get());
	instructionAppenders.back()(std::move(instruction));

	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitAssigmentStatement(CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* ctx)
{
	auto rexpression = getBuilder().buildExpression(ctx->expression());
	auto lexpression = getBuilder().buildExpression(ctx->lExpression());
	auto instruction = std::make_unique<dataStructures::ir::AssigmentStatement>(
		std::move(lexpression),
		std::move(rexpression),
		language::buildPointerToSource(filePath_.filename().string(), ctx->Asssigment()->getSymbol()->getLine()));
	language::supplyValueTo(instruction.get());

	instructionAppenders.back()(std::move(instruction));
	return antlrcpp::Any();
}
