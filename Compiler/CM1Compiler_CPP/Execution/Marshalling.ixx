module;
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

	export size_t getObjectSize(dataStructures::TypeReference type)
	{
		if (type.isPointer())
			return sizeof(void*);
		std::terminate();
	}
}

