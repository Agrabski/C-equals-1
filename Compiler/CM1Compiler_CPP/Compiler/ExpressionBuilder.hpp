#pragma once
#include <functional>
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../DataStructures/IntermidiateRepresentation/IExpression.hpp"
#include "../LanguageLogic/runtime_values.hpp"

namespace cMCompiler::compiler
{
	class ExpressionBuilder
	{
		std::unique_ptr<dataStructures::ir::IExpression> expression_;
		std::function<dataStructures::Variable* (std::string const&)> variableLookupFunction_;
	public:
		ExpressionBuilder(std::function<dataStructures::Variable* (std::string const&)> f) : variableLookupFunction_(f) {}
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext*> ctx);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext*> ctx);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext*> ctx, dataStructures::Type* requestedType);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx, dataStructures::Type* requestedType);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext *>ctx);
	};
}
