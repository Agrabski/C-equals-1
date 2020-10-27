#pragma once
#include <gsl.h>
#include <memory>
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> instantiate(gsl::not_null<dataStructures::Type*>);
}
