module;
#include <gsl/gsl>
#include <stdlib.h>
#include <list>
#include "../DataStructures/Type.hpp"
#include "../DataStructures/TypeReference.hpp"
export module Execution.Allocation;

import Execution.Marshalling;

namespace cMCompiler::execution
{
	constexpr size_t calculateObjectSize(int fieldCount)
	{
		return sizeof(MarshalledObject) + MarshalledObject::minimumObjectSize * (fieldCount - 1);
	}

	class DynamicBuffer
	{
		gsl::not_null<std::byte*> content_;
		size_t size_;
	public:
		DynamicBuffer(size_t size, size_t alignment) :
			content_(reinterpret_cast<std::byte*>(std::malloc(size))), size_(size)
		{}
	};

	class HeapComponent
	{
		size_t objectSize_;
		
	public:
		HeapComponent(int containedObjectFieldCount) :
			objectSize_(calculateObjectSize(containedObjectFieldCount))
		{}
	};

	export class CompileTimeHeap
	{

		gsl::not_null<MarshalledObject*> allocate(dataStructures::TypeReference const& type)
		{
			std::terminate();
		}
	};
}

