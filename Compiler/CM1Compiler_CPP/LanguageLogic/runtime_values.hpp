#pragma once
#include <memory>
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	class IRuntimeValue;
}

namespace cMCompiler::language
{
	using runtime_value = std::unique_ptr<dataStructures::execution::IRuntimeValue>;
}