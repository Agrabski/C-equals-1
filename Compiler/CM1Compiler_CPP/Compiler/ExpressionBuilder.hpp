#pragma once
#include <functional>
#include <filesystem>
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../LanguageLogic/runtime_values.hpp"
#include "../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	class ExpressionBuilder
	{
		std::filesystem::path filepath_;
		std::function<dataStructures::Variable* (std::string const&)> variableLookupFunction_;
		bool hasBinaryOperator(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx) const;
		std::vector<language::runtime_value> buildParameters(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx);
		language::NameResolver& nameResolver_;
		language::NameResolutionContext& context_;
	public:
		ExpressionBuilder(std::filesystem::path const& filepath, language::NameResolver& nameResolver, language::NameResolutionContext& context, std::function<dataStructures::Variable* (std::string const&)> f) :
			variableLookupFunction_(f),
			filepath_(filepath),
			nameResolver_(nameResolver),
			context_(context) {}
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext*> ctx);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent);
		language::runtime_value buildBinaryOperatorExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent);
		language::runtime_value buildAccessExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx, language::runtime_value&& referenceToParent);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext*> ctx, language::runtime_value&& referenceToParent);
		language::runtime_value buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext*> ctx, language::runtime_value&& referenceToParent);
	};
}
