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
		std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>& (std::string const&)> variableLookupFunction_;
		void visit(dataStructures::ir::ValueLiteralExpression& expression) final;
		void visit(dataStructures::ir::VariableReferenceExpression& expression) final;
		void visit(dataStructures::ir::MemberAccessExpression& expression) final;
		void visit(dataStructures::ir::FunctionCall& expression) final;
		ExpressionEvaluator(ExpressionEvaluator const& e) : resolver_(e.resolver_), context_(e.context_), variableLookupFunction_(e.variableLookupFunction_)
		{

		}
	public:
		ExpressionEvaluator(
			language::NameResolver& resolver,
			language::NameResolutionContext& context,
			std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>& (std::string const&)> variableLookupFunction) :
			resolver_(resolver), context_(context), variableLookupFunction_(variableLookupFunction) {}
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluate(gsl::not_null<dataStructures::ir::IExpression*> expression);
		std::unique_ptr<dataStructures::execution::ReferenceValue> evaluateLValue(gsl::not_null<dataStructures::ir::IExpression*> expression);
	};
}