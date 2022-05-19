module;
#include <stddef.h>
#include <gsl/gsl>
#include "../Utilities/compilation_shim.hpp"
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

	export size_t calculateObjectSize(dataStructures::TypeReference const& type)
	{
		constexpr auto baseSize = sizeof(MarshalledObject) + MarshalledObject::minimumObjectSize;
		if (type.isPointer() || type.isIntegral() || type.isCompilerIntrinsic())
			return baseSize;
		std::terminate();
	}

	constexpr size_t calculateFieldIndex(
		gsl::not_null<dataStructures::Type*> type,
		gsl::not_null<dataStructures::Field*> field)
	{
		auto base = 0;
		for (auto const f : type->fields_range())
			if (f != field)
				base += calculateObjectSize(field->type());
			else break;
		return base;
	}

	export MarshalledObject* tryGetFieldAddress(
		gsl::not_null <MarshalledObject*> object,
		gsl::not_null<dataStructures::Field*> field)
	{
		assert(object->controlBlock.containedType.referenceCount == 0);
		auto index = calculateFieldIndex(object->controlBlock.containedType.type, field);
		return reinterpret_cast<MarshalledObject*>(object->data + index);
	}
}

