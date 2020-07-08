#pragma once
#include <functional>
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../DataStructures/IntermidiateRepresentation/IExpression.hpp"

namespace cMCompiler::compiler
{
	class ExpressionBuilder
	{
		std::unique_ptr<dataStructures::ir::IExpression> expression_;
		std::function<dataStructures::Variable* (std::string const&)> variableLookupFunction_;
	public:
		ExpressionBuilder(std::function<dataStructures::Variable* (std::string const&)> f) : variableLookupFunction_(f) {}
		std::unique_ptr<dataStructures::ir::IExpression> buildExpression(CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext* ctx);
		std::unique_ptr<dataStructures::ir::IExpression> buildExpression(CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* ctx);
		std::unique_ptr<dataStructures::ir::IExpression> buildExpression(CMinusEqualsMinus1Revision0Parser::ExpressionContext* ctx);
		std::unique_ptr<dataStructures::ir::IExpression> buildExpression(CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* ctx, dataStructures::Type* requestedType);
		std::unique_ptr<dataStructures::ir::IExpression> buildExpression(CMinusEqualsMinus1Revision0Parser::FunctionCallContext* ctx, dataStructures::Type* requestedType);
		std::unique_ptr<dataStructures::ir::IExpression> buildExpression(CMinusEqualsMinus1Revision0Parser::LExpressionContext *ctx);
	};
}
