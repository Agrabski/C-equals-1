#include "FunctionBodyBuilder.hpp"
#include "ExpressionBuilder.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
#include "../DataStructures/execution/ArrayValue.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/ExpressionUtility.hpp"

void cMCompiler::compiler::FunctionBodyBuilder::enterScope(instruction_pointer& currentInstruction)
{
	variables_.push_back({});
	parents_.push_back(dataStructures::execution::ReferenceValue::make(&currentInstruction, currentInstruction->type()));
}

[[nodiscard]]
cMCompiler::language::runtime_value cMCompiler::compiler::FunctionBodyBuilder::leaveScope(unsigned long long line)
{
	auto collection = std::make_unique<dataStructures::execution::ArrayValue>(language::getCollectionTypeFor(language::getVariableDescriptor()), language::getVariableDescriptor(), 0);
	for (auto var : variables_.back())
		collection->push(std::make_unique<dataStructures::execution::RuntimeVariableDescriptor>(language::getVariableDescriptor(), var));
	auto instruction = language::buildScopeTermination(
		std::move(collection),
		language::buildPointerToSource(filePath_.filename().string(), line)
	);
	variables_.pop_back();
	return instruction;
}

cMCompiler::compiler::ExpressionBuilder cMCompiler::compiler::FunctionBodyBuilder::getBuilder()
{
	return ExpressionBuilder(filePath_, nr_, context_, [this](auto const& e) -> dataStructures::Variable*
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

cMCompiler::language::runtime_value cMCompiler::compiler::FunctionBodyBuilder::getReferenceToParent()
{
	return parents_.back()->copy();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitVariableDeclarationStatement(CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* ctx)
{
	//todo: attributes
	std::unique_ptr<dataStructures::execution::IRuntimeValue> expression;
	dataStructures::Type* type = nullptr;
	auto typeAnnotationPresent = ctx->typeSpecifier() != nullptr;
	auto referenceLevel = 0;
	if (typeAnnotationPresent)
	{
		referenceLevel = ctx->typeSpecifier()->ref().size();
		type = nr_.resolve<dataStructures::Type>(ctx->typeSpecifier()->identifier()->getText(), context_);
	}
	if (!typeAnnotationPresent || ctx->functionCallParameter())
	{
		expression = getBuilder().buildExpression(ctx->functionCallParameter());
		type = language::getExpressionType(expression);
	}

	auto name = ctx->identifier()->getText();
	// todo: infer reference
	not_null variable = function_->appendLocalVariable(name, type, referenceLevel);

	auto instruction = language::buildVariableDeclaration(
		variable,
		std::move(expression),
		language::buildSourcePointer(filePath_.filename().string(), *ctx)
	);

	language::suplyParent(instruction, getReferenceToParent());
	language::supplyScopeBegin(instruction, variable);
	instructionAppenders.back()(std::move(instruction));
	variables_.back().push_back(variable);
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitFunctionBody(CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* ctx)
{
	function_->setIrCollection(
		std::make_unique<dataStructures::execution::ArrayValue>(language::getCollectionTypeFor(
			language::getIInstruction()),
			language::getIInstruction(),
			1
			)
	);
	auto x = language::getValueFor(function_);
	enterScope(x);
	instructionAppenders.push_back([&](auto&& e)
		{
			language::suplyParent(e, getReferenceToParent());
			function_->pushInstruction(std::move(e));
		});
	auto r = visitChildren(ctx);
	instructionAppenders.back()(leaveScope(ctx->CloseBracket()->getSymbol()->getLine()));
	instructionAppenders.pop_back();
	parents_.pop_back();
	return r;
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitIfStatement(CMinusEqualsMinus1Revision0Parser::IfStatementContext* ctx)
{
	auto expression = getBuilder().buildExpression(ctx->expression(), nullptr);
	auto conditional = language::buildIf(
		std::move(expression),
		language::buildPointerToSource(filePath_.filename().string(), ctx->compoundStatement(0)->OpenBracket()->getSymbol()->getLine())
	);
	enterScope(conditional);
	instructionAppenders.push_back([&](auto&& e)
		{
			language::suplyParent(e, getReferenceToParent());
			language::pushIf(conditional, std::move(e));
		});
	ctx->compoundStatement(0)->accept(this);
	language::pushIf(conditional, leaveScope(ctx->ParamOpen()->getSymbol()->getLine()));
	instructionAppenders.pop_back();
	parents_.pop_back();


	if (ctx->compoundStatement(1) != nullptr)
	{
		enterScope(conditional);
		instructionAppenders.push_back([&](auto&& e)
			{
				language::suplyParent(e, getReferenceToParent());
				language::pushElse(conditional, std::move(e));
			});
		ctx->compoundStatement(1)->accept(this);
		auto scopeExit = leaveScope(ctx->compoundStatement(1)->CloseBracket()->getSymbol()->getLine());
		language::suplyParent(scopeExit, getReferenceToParent());
		language::pushElse(conditional, std::move(scopeExit));
		instructionAppenders.pop_back();
		parents_.pop_back();

	}
	language::suplyParent(conditional, getReferenceToParent());
	instructionAppenders.back()(std::move(conditional));

	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitFunctionCallStatement(CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext* ctx)
{
	if (ctx->Period())
	{
		auto expression = getBuilder().buildExpression(ctx->expression(), nullptr);
		not_null type = language::getExpressionType(expression);

		auto methodName = ctx->functionCall()->identifier()->getText();

		auto parameters = getBuilder().buildParameters(ctx->functionCall());

		auto result = language::buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(parameters),
			methodName,
			language::buildSourcePointer(filePath_.string(), *ctx)
		);
	}
	else
	{
		auto instruction = language::buildFunctionCallStatement(
			getBuilder().buildExpression(ctx->functionCall(), nullptr),
			language::buildSourcePointer(filePath_.string(), *ctx)
		);

		language::suplyParent(instruction, getReferenceToParent());
		instructionAppenders.back()(std::move(instruction));
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitAssigmentStatement(CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* ctx)
{
	auto rexpression = getBuilder().buildExpression(ctx->expression(1), nullptr);
	auto lexpression = getBuilder().buildExpression(ctx->expression(0), nullptr);
	auto instruction = language::buildAssigmentStatement(
		std::move(lexpression),
		std::move(rexpression),
		language::buildPointerToSource(filePath_.string(), ctx->Asssigment()->getSymbol()->getLine()));
	language::suplyParent(instruction, getReferenceToParent());

	instructionAppenders.back()(std::move(instruction));
	return antlrcpp::Any();
}
