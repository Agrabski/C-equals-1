module;
#include <gsl/gsl>
#include <stdlib.h>
#include <list>
#include <bit>
#include "../DataStructures/Type.hpp"
#include "../DataStructures/TypeReference.hpp"
export module Execution.Allocation;

import Execution.Marshalling;

namespace cMCompiler::execution
{
	constexpr size_t calculateObjectSize(dataStructures::TypeReference const& type)
	{
		constexpr auto baseSize = sizeof(MarshalledObject) + MarshalledObject::minimumObjectSize;
		if (type.isPointer() || type.isIntegral())
			return baseSize;
	}

	class DynamicBuffer
	{
		static inline constexpr auto capacity = 64;
		gsl::not_null<std::byte*> content_;
		size_t individualObjectSize_;
		uint64_t freeObjectMask_;
	public:
		DynamicBuffer(size_t size, size_t alignment) :
			content_(reinterpret_cast<std::byte*>(std::malloc(size * capacity))), individualObjectSize_(size)
		{}
		bool release(gsl::not_null<std::byte*> object) noexcept
		{
			auto index = (object.get() - content_.get()) / individualObjectSize_;
			if (index < capacity)
				freeObjectMask_ ^= (1LL << index);
			return index < capacity;

		}

		std::byte* tryGet() noexcept
		{
			auto index = std::countr_one(freeObjectMask_);
			if (index >= 64)
				return nullptr;
			freeObjectMask_ |= (1LL << index);
			return content_.get() + (index * individualObjectSize_);
		}

		constexpr bool hasCapacity() const noexcept
		{
			return freeObjectMask_ != (~0ULL);
		}

		bool containsObject(not_null<void*> object) const noexcept
		{
			return content_ <= object && object < (content_.get() + individualObjectSize_ * capacity);
		}

		~DynamicBuffer() noexcept
		{
			std::free(content_);
		}
	};

	class HeapComponent
	{
		std::vector<DynamicBuffer> buffers_;
		DynamicBuffer& getFreeBuffer()
		{
			auto buffer = std::ranges::find_if(buffers_, [](auto const& b) {return b.hasCapacity(); });
			if (buffer != buffers_.end())
				return *buffer;
			buffers_.emplace_back();
			return buffers_.back();
		}
	public:
		HeapComponent(int containedObjectFieldCount) :
			objectSize_(calculateObjectSize(containedObjectFieldCount))
		{}
		not_null<MarshalledObject*> allocate()
		{
			auto& buffer = getFreeBuffer();
			return not_null(reinterpret_cast<MarshalledObject*>(buffer.tryGet()));
		}

		void release(not_null<MarshalledObject*> object)
		{
			auto buffer = std::ranges::find_if(buffers_, [=](auto const& b) {return b.containsObject(object); });
		}
	};

	export class CompileTimeHeap
	{
		std::map<size_t, HeapComponent> heapsByObjectSize_;

		void setupControlBlock(dataStructures::TypeReference const& type, not_null<MarshalledObject*> object)
		{
			object->controlBlock.containedType = type;
		}

	public:

		gsl::not_null<MarshalledObject*> allocate(dataStructures::TypeReference const& type)
		{
			auto& heap = heapsByObjectSize_[calculateObjectSize(type)];
			auto result = heap.allocate();
			setupControlBlock(type, result);
			return result;
		}

		void release(not_null<MarshalledObject*> object)
		{
			auto& heap = heapsByObjectSize_[calculateObjectSize(object->controlBlock.containedType)];
			heap.release(object);
		}
	};
}

