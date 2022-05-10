module;
#include <stddef.h>
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
export module Execution.Marshalling;



namespace cMCompiler::execution
{
	export struct MarshalledObject
	{
		struct ControlBlock
		{
			dataStructures::TypeReference containedType;
		} controlBlock;
		static inline const size_t minimumObjectSize = alignof(void*);
		std::byte data[minimumObjectSize];
	};
	
	export constexpr size_t calculateObjectSize(dataStructures::TypeReference const& type)
	{
		constexpr auto baseSize = sizeof(MarshalledObject) + MarshalledObject::minimumObjectSize;
		if (type.isPointer() || type.isIntegral() || type.isCompilerIntrinsic())
			return baseSize;
	}

	constexpr size_t calculateFieldOffset(
		gsl::not_null<dataStructures::Type*> type,
		gsl::not_null<dataStructures::Field*> field)
	{
		auto base = offsetof(MarshalledObject, MarshalledObject::data);
		for(auto const f : type->fields_range())
			if(f != field)
				base += calculateObjectSize(field->type());
					else break;
		return base;
	}


	export size_t getObjectSize(dataStructures::TypeReference type)
	{
		if (type.isPointer())
			return sizeof(void*);
		std::terminate();
	}
}

