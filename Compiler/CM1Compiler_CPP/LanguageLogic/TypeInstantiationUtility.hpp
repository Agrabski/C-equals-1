#pragma once
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> instantiate(dataStructures::Type*);
}
