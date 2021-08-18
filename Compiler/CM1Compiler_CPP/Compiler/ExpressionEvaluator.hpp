#pragma once
#include "../LanguageLogic/NameResolver.hpp"
#include "../LanguageLogic/runtime_values.hpp"
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

		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateLiteral(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateArrayLiteral(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateBinaryOperator(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateFieldAccess(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateCall(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateVariable(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateGetAddress(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateConstructor(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateNew(language::runtime_value& expression);
		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateDereference(language::runtime_value& expression);

		std::unique_ptr<dataStructures::execution::IRuntimeValue> evaluateCommon(language::runtime_value& expression);

	public:
		ExpressionEvaluator(
			std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>& (std::string const&)> variableLookupFunction) :
			variableLookupFunction_(variableLookupFunction) {}

		std::unique_ptr< dataStructures::execution::IRuntimeValue> evaluate(language::runtime_value& expression, bool expectNull);
		std::unique_ptr< dataStructures::execution::ReferenceValue> evaluateLeftExpression(language::runtime_value& expression);
	};
}