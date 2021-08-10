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
#include "../LanguageLogic/TypeCoercionUtility.hpp"
#include "TypeUtility.hpp"

std::string cMCompiler::compiler::FunctionBodyBuilder::decorateTemporary(not_null<antlr4::tree::ParseTree*>tree, int index)
{
	return "$$_temporary" + language::getLineNumber(tree) + std::to_string(index);
}

std::string cMCompiler::compiler::FunctionBodyBuilder::decorateRangeLoopEndVariableName(std::string const& original)
{
	return "$$_" + original;
}

void cMCompiler::compiler::FunctionBodyBuilder::enterScope(instruction_pointer& currentInstruction)
{
	variables_.push_back({});
	parents_.push_back(currentInstruction->copy());
}

[[nodiscard]]
cMCompiler::language::runtime_value cMCompiler::compiler::FunctionBodyBuilder::leaveScope(unsigned long long line)
{
	auto collection = std::make_unique<dataStructures::execution::ArrayValue>(dataStructures::TypeReference{ language::getCollectionTypeFor({ language::getVariableDescriptor(),0 }), 0 }, dataStructures::TypeReference{ language::getVariableDescriptor(), 0 });
	for (auto var : variables_.back())
		collection->push(std::make_unique<dataStructures::execution::RuntimeVariableDescriptor>(dataStructures::TypeReference{ language::getVariableDescriptor(), 0 }, var));
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


void cMCompiler::compiler::FunctionBodyBuilder::buildForLoop(
	std::string const& variableName,
	std::function<language::runtime_value()> variableInitialisationExpressionFactory,
	std::function<language::runtime_value(not_null<dataStructures::Variable*>)> testExpressionFactory,
	std::function<void(not_null<dataStructures::Variable*>)> postExpressionFactory,
	gsl::not_null<antlr4::tree::ParseTree*> body,
	std::function<void(not_null<dataStructures::Variable*>)> actionInNewScope)
{
	auto initialisationExpression = variableInitialisationExpressionFactory();
	// todo: reference level
	not_null variable = function_->appendLocalVariable(
		variableName,
		language::getExpressionType(initialisationExpression)
	);

	auto testExpression = testExpressionFactory(variable);

	auto assigment = language::buildVariableDeclaration(
		variable,
		std::move(initialisationExpression),
		language::buildSourcePointer(filePath_.string(), *body->parent)
	);
	language::suplyParent(assigment, getReferenceToParent());
	language::supplyScopeBegin(assigment, variable);
	instructionAppenders.back()(std::move(assigment));
	variables_.back().push_back(variable);

	buildWhileLoop(
		std::move(testExpression),
		body,
		[&]() {actionInNewScope(variable); },
		[&]()
		{
			postExpressionFactory(variable);
		}
	);


}

void cMCompiler::compiler::FunctionBodyBuilder::buildWhileLoop(
	language::runtime_value&& expression,
	not_null<antlr4::tree::ParseTree*> body,
	std::function<void()> actionInNewScope,
	std::function<void()> actionAtEndOfNewScope
)
{
	auto loop = language::buildWhileLoop(std::move(expression), language::buildSourcePointer(filePath_.string(), *body->parent));
	enterScope(loop);
	instructionAppenders.push_back([&](auto&& e)
		{
			language::suplyParent(e, getReferenceToParent());
			language::pushWhile(loop, std::move(e));
		});
	actionInNewScope();
	body->accept(this);
	actionAtEndOfNewScope();
	auto scopeExit = leaveScope(22); // todo: line number
	language::suplyParent(scopeExit, getReferenceToParent());
	language::pushWhile(loop, std::move(scopeExit));
	instructionAppenders.pop_back();
	parents_.pop_back();
	instructionAppenders.back()(std::move(loop));
}

void cMCompiler::compiler::FunctionBodyBuilder::buildForRangeLoop(
	std::string const& variableName,
	language::runtime_value&& expression,
	not_null<antlr4::tree::ParseTree*> body)
{
	auto expressionType = language::getExpressionType(expression);
	auto expressionMethods = expressionType.type->methods();
	auto iterateMethod = std::find_if(expressionMethods.begin(), expressionMethods.end(), [](const auto e) {return e->name() == "iterate"; });
	not_null rangeObjectVariable = function_->appendLocalVariable(
		decorateTemporary(body, 0),
		(*iterateMethod)->returnType()
	);
	{
		auto assigment = language::buildVariableDeclaration(
			rangeObjectVariable,
			language::buildMethodCallExpression(
				std::move(expression),
				expressionType,
				{},
				"iterate",
				language::buildSourcePointer(filePath_.string(), *body->parent)
			),
			language::buildSourcePointer(filePath_.string(), *body->parent)
		);
		language::suplyParent(assigment, getReferenceToParent());
		language::supplyScopeBegin(assigment, rangeObjectVariable);
		instructionAppenders.back()(std::move(assigment));
		variables_.back().push_back(rangeObjectVariable);
	}

	auto methods = rangeObjectVariable->type().type->methods();
	auto begin = std::find_if(methods.begin(), methods.end(), [](auto e) {return e->name() == "begin"; });
	auto beginMethods = (*begin)->returnType().type->methods();
	auto get = std::find_if(beginMethods.begin(), beginMethods.end(), [](auto const e)
		{
			return e->name() == "get";
		});

	// todo: reference level
	auto variable = function_->appendLocalVariable(variableName, (*get)->returnType());

	// todo: jesus fucking christ


	buildForLoop(
		decorateTemporary(body, 1),
		[=]()
		{
			return language::buildMethodCallExpression(
				language::buildVariableReferenceExpressionDescriptor(rangeObjectVariable),
				rangeObjectVariable->type(),
				{},
				"begin",
				language::buildSourcePointer(filePath_.string(), *body->parent)
			);
		},
		[=](auto e)
		{
			return language::buildBinaryOperatorExpression(
				nr_,
				context_,
				"!=",
				language::buildVariableReferenceExpressionDescriptor(e),
				language::buildMethodCallExpression(
					language::buildVariableReferenceExpressionDescriptor(rangeObjectVariable),
					rangeObjectVariable->type(),
					{},
					"end",
					language::buildSourcePointer(filePath_.string(), *body->parent)
				),
				language::buildSourcePointer(filePath_.string(), *body->parent)
			);
		},
			[this, body](auto e)
		{
			auto instruction = language::buildFunctionCallStatement(
				language::buildMethodCallExpression(
					language::buildVariableReferenceExpressionDescriptor(e),
					e->type(),
					{},
					"advance",
					language::buildSourcePointer(filePath_.string(), *body->parent)),
				language::buildSourcePointer(filePath_.string(), *body->parent)
			);
			instructionAppenders.back()(std::move(instruction));
		},
			body,
			[variable, this, body](auto e) -> void
		{
			variables_.back().push_back(variable);
			auto assigment = language::buildVariableDeclaration(
				variable,
				language::buildMethodCallExpression(
					language::buildVariableReferenceExpressionDescriptor(e),
					e->type(),
					{},
					"get",
					language::buildSourcePointer(filePath_.string(), *body->parent)
				),
				language::buildSourcePointer(filePath_.string(), *body->parent)
			);
			language::suplyParent(assigment, getReferenceToParent());
			language::supplyScopeBegin(assigment, variable);
			instructionAppenders.back()(std::move(assigment));
		}
		);
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitRangeForStatement(
	CMinusEqualsMinus1Revision0Parser::RangeForStatementContext* ctx)
{
	buildForRangeLoop(
		ctx->identifier()->getText(),
		getBuilder().buildExpression(ctx->expression(), nullptr),
		ctx->compoundStatement()
	);
	return {};
}

cMCompiler::language::runtime_value cMCompiler::compiler::FunctionBodyBuilder::getReferenceToParent()
{
	return parents_.back()->copy();
}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitVariableDeclarationStatement(CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* ctx)
{
	//todo: attributes
	std::unique_ptr<dataStructures::execution::IRuntimeValue> expression;
	dataStructures::TypeReference type{};
	auto typeAnnotationPresent = ctx->typeSpecifier() != nullptr;
	if (typeAnnotationPresent)
		type = getType(
			nr_,
			context_,
			ctx->typeSpecifier(),
			filePath_);
	if (!typeAnnotationPresent || ctx->functionCallParameter())
	{
		expression = getBuilder().buildExpression(ctx->functionCallParameter());
		type = language::getExpressionType(expression);
	}

	auto name = ctx->identifier()->getText();
	// todo: infer reference
	not_null variable = function_->appendLocalVariable(name, type);

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
		std::make_unique<dataStructures::execution::ArrayValue>(dataStructures::TypeReference{ language::getCollectionTypeFor(
			dataStructures::TypeReference{ language::getIInstruction(), 1 }), 0 },
			dataStructures::TypeReference{ language::getIInstruction() ,1 }
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
		language::buildSourcePointer(filePath_.string(), *ctx)
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
		auto scopeExit = leaveScope(language::getLineNumber(ctx));
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
		auto type = language::getExpressionType(expression);

		auto methodName = ctx->functionCall()->identifier()->getText();

		auto parameters = getBuilder().buildParameters(ctx->functionCall());

		auto result = language::buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(parameters),
			methodName,
			language::buildSourcePointer(filePath_.string(), *ctx)
		);

		auto instruction = language::buildFunctionCallStatement(
			std::move(result),
			language::buildSourcePointer(filePath_.string(), *ctx)
		);

		language::suplyParent(instruction, getReferenceToParent());
		instructionAppenders.back()(std::move(instruction));
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

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitReturnStatement(CMinusEqualsMinus1Revision0Parser::ReturnStatementContext* ctx)
{
	assert(ctx != nullptr);
	auto sourcePointer = language::buildSourcePointer(filePath_.string(), *ctx);
	if (ctx->expression() != nullptr)
	{
		auto exp = getBuilder().buildExpression(not_null{ ctx->expression() }, nullptr);
		auto expType = language::getExpressionType(exp);
		if(!language::coerce(expType, function_->returnType()))
			assert(false);
		instructionAppenders.back()(language::buildReturnStatement(std::move(exp), std::move(sourcePointer)));
	}
	else
		instructionAppenders.back()(language::buildReturnStatement(std::move(sourcePointer)));
	return {};

}

antlrcpp::Any cMCompiler::compiler::FunctionBodyBuilder::visitWhileStatement(CMinusEqualsMinus1Revision0Parser::WhileStatementContext* ctx)
{
	auto expression = getBuilder().buildExpression(ctx->whileHeader()->expression(), nullptr);
	buildWhileLoop(
		std::move(expression),
		ctx->compoundStatement(),
		[]() {},
		[]() {});
	return {};
}
