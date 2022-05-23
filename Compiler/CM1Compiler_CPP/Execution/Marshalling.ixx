module;
#include <stddef.h>
#include <compare>
#include <gsl/gsl>
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../Utilities/compilation_shim.hpp"
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
export module Execution.Marshalling;



namespace cMCompiler::execution
{
	struct MarshalledObject;
	export template<typename T>
		dataStructures::TypeReference getTypeFor();

		export struct ControlBlock
	{
		dataStructures::TypeReference containedType;
	};

	export template<typename T>
		concept marshalled_object = requires(T t)
	{
		{t.controlBlock}-> std::same_as<ControlBlock&>;
		{t.getDataPointer()}-> std::same_as<std::byte*>;
	};

	export template<typename T>
		concept marshallable_native_object = requires(T t)
	{
		{getTypeFor<T>()} -> std::same_as<dataStructures::TypeReference>;
	}&&
		std::default_initializable<T>&&
		std::copyable<T>&&
		std::move_constructible<T>;

	export struct MarshalledObject
	{
		ControlBlock controlBlock;
		static inline const size_t minimumObjectSize = alignof(void*);
		std::byte data[minimumObjectSize];
		std::byte* getDataPointer() noexcept
		{
			return data;
		}
		MarshalledObject() = default;
		MarshalledObject(dataStructures::TypeReference type)
		{
			controlBlock.containedType = type;
		}

		template<typename T>
		MarshalledObject(dataStructures::TypeReference type, T&& value) : MarshalledObject(type)
		{
			*reinterpret_cast<T*>(data) = value;
		}
	};

	export struct MarshalledPointer
	{
		ControlBlock controlBlock;
		static inline const size_t minimumObjectSize = alignof(void*);
		MarshalledObject* data;
		std::byte* getDataPointer() noexcept
		{
			return reinterpret_cast<std::byte*>(&data);
		}
		MarshalledPointer() = default;
		MarshalledPointer(dataStructures::TypeReference type)
		{
			controlBlock.containedType = type;
		}

		MarshalledPointer(dataStructures::TypeReference type, MarshalledObject* value) : MarshalledPointer(type)
		{
			data = value;
		}

		auto operator==(MarshalledPointer const& other) const noexcept
		{
			return other.data == data && controlBlock.containedType == other.controlBlock.containedType;
		}
	};

	export template<marshallable_native_object T>
		struct MarshalledNativeObject
	{
		ControlBlock controlBlock;
		T data;
		std::byte* getDataPointer()
		{
			return reinterpret_cast<std::byte*>(&data);
		}

		MarshalledNativeObject() : data()
		{
			controlBlock = ControlBlock
			{
				getTypeFor<T>()
			};
		}
		MarshalledNativeObject(T&& value) : MarshalledNativeObject()
		{
			data = std::move(value);
		}

		bool operator==(MarshalledNativeObject<T>const& other)const noexcept
		{
			return other.data == data && controlBlock.containedType == other.controlBlock.containedType;
		}
	};

	export size_t calculateObjectSize(dataStructures::TypeReference const& type)
	{
		if (type == dataStructures::TypeReference{ language::getString(), 0 })
			return sizeof(MarshalledNativeObject<std::string>);
		if (type.isPointer() || type.isIntegral() || type.isCompilerIntrinsic())
			return sizeof(MarshalledObject);
		auto result = sizeof(ControlBlock);
		for (auto const field : type.type->fields())
			result += calculateObjectSize(field->type());

		assert(
			result >= sizeof(MarshalledObject) &&
			"Attempting to allocate an empty object"
		);

		return result;
	}

	size_t calculateFieldIndex(
		gsl::not_null<dataStructures::Type*> type,
		gsl::not_null<dataStructures::Field*> field)
	{
		size_t base = 0;
		for (auto const f : type->fields())
			if (f != field)
				base += calculateObjectSize(field->type());
			else break;
		return base;
	}

	export template<marshalled_object T>
		MarshalledObject* tryGetFieldAddress(
			gsl::not_null <T*> object,
			gsl::not_null<dataStructures::Field*> field)
	{
		assert(object->controlBlock.containedType.referenceCount == 0);
		auto index = calculateFieldIndex(object->controlBlock.containedType.type, field);
		return reinterpret_cast<MarshalledObject*>(object->getDataPointer() + index);
	}
}

