#pragma once
#include <ranges>
#include "../LanguageLogic/runtime_values.hpp"
#include "../DataStructures/AttributeTarget.hpp"
#include "../DataStructures/Attribute.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::compiler
{
	void executeAttributeFunctionsForStatement(language::runtime_value& statement);
	void executeAttachmentFunctionForExpression(not_null<dataStructures::execution::IRuntimeValue*> expression);
}

