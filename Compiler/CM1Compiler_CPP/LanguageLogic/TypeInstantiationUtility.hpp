#pragma once
#include <gsl.h>
#include <memory>
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../DataStructures/execution/ObjectValue.hpp"

namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> instantiate(gsl::not_null<dataStructures::Type*>);
	std::unique_ptr<dataStructures::execution::ReferenceValue> heapAllocate(gsl::not_null<dataStructures::Type*>, bool unique = true);
	std::pair<
		std::unique_ptr<dataStructures::execution::IRuntimeValue>,
		dataStructures::execution::ObjectValue&
	> heapAllocateObject(gsl::not_null<dataStructures::Type*>, bool unique = true);
}
