#pragma once
#include "../LanguageLogic/NameResolver.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ObjectValue.hpp"
#include "../DataStructures/execution/ReferenceValue.hpp"

namespace cMCompiler::compiler
{
	class ExpressionEvaluator
	{
		bool makeReference_ = false;
		std::unique_ptr<dataStructures::execution::IRuntimeValue> value_;
		std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>& (std::string const&)> variableLookupFunction_;
		ExpressionEvaluator(ExpressionEvaluator const& e) : variableLookupFunction_(e.variableLookupFunction_)
		{
		}

		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateLiteral(dataStructures::execution::IRuntimeValue& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateFieldAccess(dataStructures::execution::IRuntimeValue& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateCall(dataStructures::execution::IRuntimeValue& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateVariable(dataStructures::execution::IRuntimeValue& expression);

		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateCommon(dataStructures::execution::IRuntimeValue& expression);

	public:
		ExpressionEvaluator(
			std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>& (std::string const&)> variableLookupFunction) :
			variableLookupFunction_(variableLookupFunction) {}

		std::unique_ptr< dataStructures::execution::IRuntimeValue> evaluate(dataStructures::execution::IRuntimeValue& expression);
		std::unique_ptr< dataStructures::execution::ReferenceValue> evaluateLeftExpression(dataStructures::execution::IRuntimeValue& expression);
	};
}