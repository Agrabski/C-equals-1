module;
#include "../DataStructures/Type.hpp"
export module Execution.Marshalling;



namespace cMCompiler::execution
{
	export struct MarshalledObject
	{
		static inline const size_t minimumObjectSize = alignof(void*);
		dataStructures::TypeReference containedType;
		std::byte data[minimumObjectSize];
	};

	export size_t getObjectSize(dataStructures::TypeReference type)
	{
		if (type.isPointer())
			return sizeof(void*);
		std::terminate();
	}
}

