module;
#include "../DataStructures/Type.hpp"
export module Marshalling;



namespace cMCompiler::Execution
{
	export template<size_t Size>
	struct MarshalledObject
	{
		dataStructures::TypeReference containedType;
		std::array<std::byte, Size> data;
	};

	export size_t getObjectSize(dataStructures::TypeReference type)
	{
		if (type.isPointer())
			return sizeof(void*);
	}
}

