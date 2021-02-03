#include "ExpressionBuilder.hpp"
#include "../LanguageLogic/ExpressionUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../DataStructures/IntermidiateRepresentation/VariableReferenceExpression.hpp"
#include "../DataStructures/IntermidiateRepresentation/ValueLiteralExpression.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../DataStructures/IntermidiateRepresentation/MemberAccessExpression.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"

using namespace cMCompiler::dataStructures::ir;
using namespace cMCompiler::compiler;


cMCompiler::language::runtime_value ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext*> ctx)
{
	if (ctx->expression() != nullptr)
		return buildExpression(ctx->expression());
	if (ctx->arithmeticExpression() != nullptr)
		return buildExpression(ctx->arithmeticExpression(), nullptr);
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext*> ctx)
{
	if (ctx->Identifier() != nullptr)
		return language::buildVariableReferenceExpression(variableLookupFunction_(ctx->Identifier()->getText()));
	return language::runtime_value();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx)
{
	if (ctx->Identifier() != nullptr)
		return language::buildVariableReferenceExpression(variableLookupFunction_(ctx->Identifier()->getText()));
	if (ctx->STRING())
	{
		auto text = ctx->STRING()->getText();
		text.erase(text.begin());
		text.erase(text.end() - 1);
		auto value = language::buildStringValue();
		value->setValue(text);
		return language::buildValueLiteralExpression(std::move(value));
	}
	if (ctx->lExpression())
		return buildExpression(ctx->lExpression());
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext*> ctx, dataStructures::Type* requestedType)
{
	using namespace dataStructures::execution;
	if (ctx->IntegerLiteral())
	{
		auto lit = language::buildIntegerValue(requestedType);
		lit->fromString(ctx->IntegerLiteral()->getText());
		auto result = language::buildValueLiteralExpression(std::move(lit));
		return std::move(result);
	}
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext*> ctx)
{
	using namespace cMCompiler::dataStructures::ir;
	auto const identifierChain = ctx->Identifier();
	auto variableAccess = language::buildVariableReferenceExpression(variableLookupFunction_(identifierChain[0]->getText()));
	auto strings = std::vector<std::string>();
	for (not_null id : identifierChain)
		strings.push_back(id->getText());
	strings.erase(strings.begin());
	return language::buildValueMemberAccessExpression(std::move(variableAccess), language::convertToCollection(strings));
}
