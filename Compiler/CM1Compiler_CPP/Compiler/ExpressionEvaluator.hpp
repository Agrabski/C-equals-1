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
	public:
		ExpressionEvaluator(
			std::function<std::unique_ptr<dataStructures::execution::IRuntimeValue>& (std::string const&)> variableLookupFunction) :
			variableLookupFunction_(variableLookupFunction) {}

		std::unique_ptr< dataStructures::execution::IRuntimeValue> evaluate(dataStructures::execution::IRuntimeValue & expression);
	};
}