#pragma once
#include <gsl.h>
#include <memory>
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../DataStructures/execution/ObjectValue.hpp"

namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> instantiate(dataStructures::TypeReference);
	std::unique_ptr<dataStructures::execution::ReferenceValue> heapAllocate(dataStructures::TypeReference, bool unique = true);
	std::pair<
		std::unique_ptr<dataStructures::execution::IRuntimeValue>,
		dataStructures::execution::ObjectValue&
	> heapAllocateObject(gsl::not_null<dataStructures::Type*>, bool unique = true);

	std::unique_ptr<dataStructures::execution::ReferenceValue> moveToHeap(std::unique_ptr<dataStructures::execution::IRuntimeValue>&&);
}
