#include "ExpressionBuilder.hpp"
#include "../DataStructures/IntermidiateRepresentation/VariableReferenceExpression.hpp"

using namespace cMCompiler::dataStructures::ir;
using namespace cMCompiler::compiler;


std::unique_ptr<IExpression> ExpressionBuilder::buildExpression(CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext* ctx)
{
	if (ctx->expression() != nullptr)
		return buildExpression(ctx->expression());
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
	return nullptr;
}
