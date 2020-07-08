#pragma once
#include "../LanguageLogic/NameResolver.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ObjectValue.hpp"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../DataStructures/IntermidiateRepresentation/IExpression.hpp"
#include "../DataStructures/IntermidiateRepresentation/IExpressionVisitor.hpp"

namespace cMCompiler::compiler
{
	class ExpressionEvaluator : dataStructures::ir::IExpressionVisitor
	{
		bool makeReference_ = false;
		language::NameResolver& resolver_;
		language::NameResolutionContext& context_;
		std::unique_ptr<dataStructures::execution::IRuntimeValue> value_;
		std::function<dataStructures::execution::IRuntimeValue* (std::string const&)> variableLookupFunction_;
		void visit(cMCompiler::dataStructures::ir::ValueLiteralExpression& expression) final;
		void visit(cMCompiler::dataStructures::ir::VariableReferenceExpression& expression) final;
	public:
		ExpressionEvaluator(
			language::NameResolver& resolver,
			language::NameResolutionContext& context,
			std::function<dataStructures::execution::IRuntimeValue* (std::string const&)> variableLookupFunction) :
			resolver_(resolver), context_(context), variableLookupFunction_(variableLookupFunction) {}
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluate(gsl::not_null<dataStructures::ir::IExpression*> expression);
		std::unique_ptr<dataStructures::execution::ReferenceValue> evaluateLValue(gsl::not_null<dataStructures::ir::IExpression*> expression);

	};
}