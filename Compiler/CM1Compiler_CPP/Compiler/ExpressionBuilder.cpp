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
		return buildExpression(ctx->expression());
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
		result.push_back(buildExpression(param->expression()));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx)
{
	if (ctx->Period() != nullptr)
		return buildAccessExpression(ctx);
	if (ctx->functionCall() != nullptr)
		return buildExpression(ctx->functionCall());
	if (ctx->throwExpression() != nullptr)
		return buildExpression(ctx->throwExpression());
	if (ctx->newExpression() != nullptr)
		return buildExpression(ctx->newExpression());
	if (hasBinaryOperator(ctx))
		return buildBinaryOperatorExpression(ctx);
	if (ctx->Identifier() != nullptr)
	{
		auto variableName = ctx->Identifier()->getText();
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
		return language::buildValueLiteralExpression(std::move(value));
	}
	if (ctx->IntegerLiteral() != nullptr)
	{
		using namespace dataStructures::execution;
		if (ctx->IntegerLiteral())
		{
			auto lit = language::buildIntegerValue(language::getUsize());
			lit->fromString(ctx->IntegerLiteral()->getText());
			auto result = language::buildValueLiteralExpression(std::move(lit));
			return std::move(result);
		}
	}
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildBinaryOperatorExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx)
{
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildAccessExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx)
{
	auto expression = buildExpression(ctx->expression(0));
	auto type = language::getExpressionType(expression);
	if (ctx->functionCall() != nullptr)
	{
		auto methodName = ctx->functionCall()->Identifier()->getText();

		auto parameters = buildParameters(ctx->functionCall());

		return language::buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(parameters),
			methodName,
			language::buildSourcePointer(filepath_.string(), *ctx) // todo: pass filename
		);
	}
	else
	{
		assert(ctx->Identifier() != nullptr);
		auto fieldName = ctx->Identifier()->getText();
		auto fields = type->fields();
		auto field = std::find_if(fields.begin(), fields.end(), [&](auto const e) {return e->name() == fieldName; });
		assert(field != fields.end());
		return language::buildFieldAccessExpression(
			std::move(expression),
			*field
		);
	}
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx)
{
	std::terminate();
}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::MemberAccessExpressionContext*> ctx)
//{
//	if (ctx->Identifier() != nullptr)
//		return language::buildMemberAccessExpression(variableLookupFunction_(ctx->Identifier()->getText()), buildExpression(ctx->expression()));
//	else
//		return language::buildMemberAccessExpression(buildExpression(ctx->functionCall()), buildExpression(ctx->expression()));
//}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext*> ctx)
{
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext*> ctx)
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

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext*> ctx)
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
