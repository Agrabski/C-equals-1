#include "ExpressionBuilder.hpp"
#include "../LanguageLogic/ExpressionUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"

using namespace cMCompiler::dataStructures::ir;
using namespace cMCompiler::compiler;


cMCompiler::language::runtime_value ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext*> ctx)
{
	if (ctx->expression() != nullptr)
		return buildExpression(ctx->expression(), nullptr);
	std::terminate();
}

bool cMCompiler::compiler::ExpressionBuilder::hasBinaryOperator(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx) const
{
	return
		ctx->comparsionOperator() != nullptr ||
		ctx->logicalBinaryOperator() != nullptr ||
		ctx->arithmeticBinaryOperator() != nullptr;
}

std::vector<cMCompiler::language::runtime_value> cMCompiler::compiler::ExpressionBuilder::buildParameters(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx)
{
	auto result = std::vector<language::runtime_value>();

	for (auto param : ctx->functionCallParameter())
		result.push_back(buildExpression(param->expression(), nullptr));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	if (ctx->Period() != nullptr)
		return buildAccessExpression(ctx, std::move(referenceToParent));
	if (ctx->functionCall() != nullptr)
		return buildExpression(ctx->functionCall(), std::move(referenceToParent));
	if (ctx->throwExpression() != nullptr)
		return buildExpression(ctx->throwExpression(), std::move(referenceToParent));
	if (ctx->newExpression() != nullptr)
		return buildExpression(ctx->newExpression(), std::move(referenceToParent));
	if (hasBinaryOperator(ctx))
		return buildBinaryOperatorExpression(ctx, std::move(referenceToParent));
	if (ctx->identifier() != nullptr)
	{
		auto variableName = ctx->identifier()->getText();
		auto variable = variableLookupFunction_(variableName);
		if (variable == nullptr)
			std::terminate();
		return language::buildVariableReferenceExpressionDescriptor(variable);
	}
	if (ctx->STRING())
	{
		auto text = ctx->STRING()->getText();
		text.erase(text.begin());
		text.erase(text.end() - 1);
		auto value = language::buildStringValue();
		value->setValue(text);
		// todo: parent
		auto result = language::buildValueLiteralExpression(
			std::move(value),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
		language::setParent(result.get(), std::move(referenceToParent));
	}
	if (ctx->IntegerLiteral() != nullptr)
	{
		using namespace dataStructures::execution;
		if (ctx->IntegerLiteral())
		{
			auto lit = language::buildIntegerValue(language::getUsize());
			lit->fromString(ctx->IntegerLiteral()->getText());
			auto result = language::buildValueLiteralExpression(
				std::move(lit),
				language::buildSourcePointer(filepath_.string(), *ctx)
			);
			language::setParent(result.get(), std::move(referenceToParent));
			return result;
		}
	}
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildBinaryOperatorExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildAccessExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto expression = buildExpression(ctx->expression(0), nullptr);
	not_null type = language::getExpressionType(expression);
	if (ctx->functionCall() != nullptr)
	{
		auto methodName = ctx->functionCall()->identifier()->getText();

		auto parameters = buildParameters(ctx->functionCall());

		auto result = language::buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(parameters),
			methodName,
			language::buildSourcePointer(filepath_.string(), *ctx) // todo: pass filename
		);
		language::setParent(result.get(), std::move(referenceToParent));
	}
	else
	{
		assert(ctx->identifier() != nullptr);
		auto fieldName = ctx->identifier()->getText();
		auto fields = type->fields();
		auto field = std::find_if(fields.begin(), fields.end(), [&](auto const e) noexcept {return e->name() == fieldName; });
		assert(field != fields.end());
		auto result = language::buildFieldAccessExpression(
			std::move(expression),
			*field,
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
		language::setParent(result.get(), std::move(referenceToParent));
		return result;
	}
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto arguments = buildParameters(ctx);
	// todo: generics
	// todo: operators

	auto name = ctx->identifier()->getText();
	auto candidates = nameResolver_.resolveOverloadSet(ctx->identifier()->getText(), context_);
	auto compileTime = language::resolveOverload(candidates, arguments, true, false);
	auto runtime = language::resolveOverload(candidates, arguments, false, true);
	return language::buildFunctionCallStatement(
		language::getValueFor(compileTime),
		language::getValueFor(runtime),
		language::convertCollection(std::move(arguments), language::getExpressionDescriptor(), 1),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::MemberAccessExpressionContext*> ctx, language::runtime_value&& referenceToParent)
//{
//	if (ctx->Identifier() != nullptr)
//		return language::buildMemberAccessExpression(variableLookupFunction_(ctx->Identifier()->getText()), buildExpression(ctx->expression()));
//	else
//		return language::buildMemberAccessExpression(buildExpression(ctx->functionCall()), buildExpression(ctx->expression()));
//}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::terminate();
}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext*> ctx, dataStructures::Type* requestedType)
//{
//	using namespace dataStructures::execution;
//	if (ctx->IntegerLiteral())
//	{
//		auto lit = language::buildIntegerValue(requestedType);
//		lit->fromString(ctx->IntegerLiteral()->getText());
//		auto result = language::buildValueLiteralExpression(std::move(lit));
//		return std::move(result);
//	}
//}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext*> ctx, language::runtime_value&& referenceToParent)
//{
//	using namespace cMCompiler::dataStructures::ir;
//	auto const identifierChain = ctx->Identifier();
//	auto variableAccess = language::buildVariableReferenceExpression(variableLookupFunction_(identifierChain[0]->getText()));
//	auto strings = std::vector<std::string>();
//	for (not_null id : identifierChain)
//		strings.push_back(id->getText());
//	strings.erase(strings.begin());
//	return language::buildValueMemberAccessExpression(std::move(variableAccess), language::convertToCollection(strings));
//}
