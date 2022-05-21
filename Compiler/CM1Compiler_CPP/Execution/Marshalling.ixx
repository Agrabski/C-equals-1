module;
#include <stddef.h>
#include <gsl/gsl>
#include "../Utilities/compilation_shim.hpp"
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
export module Execution.Marshalling;



namespace cMCompiler::execution
{
	export struct ControlBlock
	{
		dataStructures::TypeReference containedType;
	};

	export template<typename T>
		concept marshalled_object = requires(T t)
	{
		{t.controlBloc}-> std::same_as<ControlBlock>;
		{t.getDataPointer()}-> std::same_as<std::byte*>;
	};

	export struct MarshalledObject
	{
		ControlBlock controlBlock;
		static inline const size_t minimumObjectSize = alignof(void*);
		std::byte data[minimumObjectSize];
		std::byte* getDataPointer()
		{
			return data;
		}
	};

	export template<typename T>
		struct MarshalledNativeObject
	{
		ControlBlock controlBlock;
		T data;
		std::byte* getDataPointer()
		{
			return reinterpret_cast<std::byte*>(&data);
		}
	};

	export size_t calculateObjectSize(dataStructures::TypeReference const& type)
	{
		if (type.isPointer() || type.isIntegral() || type.isCompilerIntrinsic())
			return sizeof(MarshalledObject);
		auto result = sizeof(ControlBlock);
		for (auto const field : type.type->fields_range())
			result += calculateObjectSize(field->type());
		assert(result >= sizeof(MarshalledObject));
		return result;
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

