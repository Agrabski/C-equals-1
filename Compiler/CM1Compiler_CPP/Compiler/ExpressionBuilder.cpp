#include "ExpressionBuilder.hpp"
#include "../DataStructures/IntermidiateRepresentation/VariableReferenceExpression.hpp"
#include "../DataStructures/IntermidiateRepresentation/ValueLiteralExpression.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"

using namespace cMCompiler::dataStructures::ir;
using namespace cMCompiler::compiler;


std::unique_ptr<IExpression> ExpressionBuilder::buildExpression(CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext* ctx)
{
	if (ctx->expression() != nullptr)
		return buildExpression(ctx->expression());
	if (ctx->arithmeticExpression() != nullptr)
		return buildExpression(ctx->arithmeticExpression(), nullptr);
}

std::unique_ptr<IExpression> cMCompiler::compiler::ExpressionBuilder::buildExpression(CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* ctx)
{
	if (ctx->Identifier() != nullptr)
		return std::make_unique<dataStructures::ir::VariableReferenceExpression>(
			variableLookupFunction_(ctx->Identifier()->getText())
			);
	return std::unique_ptr<dataStructures::ir::IExpression>();
}

std::unique_ptr<IExpression> cMCompiler::compiler::ExpressionBuilder::buildExpression(CMinusEqualsMinus1Revision0Parser::ExpressionContext* ctx)
{
	if (ctx->Identifier() != nullptr)
	{
		return std::make_unique<dataStructures::ir::VariableReferenceExpression>(
			variableLookupFunction_(ctx->Identifier()->getText())
			);
	}
	if (ctx->STRING())
	{
		auto text = ctx->STRING()->getText();
		text.erase(text.begin());
		text.erase(text.end());
		auto value = language::buildStringValue();
		value->setValue(text);
		return std::make_unique<dataStructures::ir::ValueLiteralExpression>(std::move(value));
	}
	std::terminate();
}

std::unique_ptr<IExpression> cMCompiler::compiler::ExpressionBuilder::buildExpression(CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* ctx, dataStructures::Type* requestedType)
{
	using namespace dataStructures::execution;
	if (ctx->IntegerLiteral())
	{
		auto lit = language::buildIntegerValue(requestedType);
		lit->fromString(ctx->IntegerLiteral()->getText());
		auto result = std::make_unique<ValueLiteralExpression>(std::move(lit));
		return std::move(result);
	}
}
