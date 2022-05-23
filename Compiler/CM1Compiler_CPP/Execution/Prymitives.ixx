module;

#include <cassert>
#include "Utility.hpp"
#include "../Utilities/compilation_shim.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../DataStructures/TypeReference.hpp"
#include "../DataStructures/SourcePointer.hpp"
#include "../LanguageLogic/IRUtility.hpp"
export module Execution.Prymitives;
import Execution.Marshalling;
import <gsl/gsl>;

namespace cMCompiler::execution
{	export template<>
		dataStructures::TypeReference getTypeFor<unsigned long long>()
	{
		return { language::getUsize(), 0 };
	}

	export template<typename T>
		void setPrymitiveValue(gsl::not_null<MarshalledObject*> object, T&& value)
	{
		// todo: assert correctness
		(*reinterpret_cast<T*>(object->data)) = value;
	}

	export template<typename T>
		T& getPrymitiveValue(gsl::not_null<MarshalledObject*> object)
	{
		// todo: assert correctness
		return (*reinterpret_cast<T*>(object->data));
	}

	export MarshalledObject* tryDereferencePointer(gsl::not_null<MarshalledObject*> object)
	{
		assert(object->controlBlock.containedType.isPointer());
		return reinterpret_cast<MarshalledObject*>(object->getDataPointer());
	}

	export void setPointerValue(gsl::not_null<MarshalledObject*> pointer, MarshalledObject* value)
	{
		assert(pointer->controlBlock.containedType.isPointer());
		if (value != nullptr)
			assert(pointer->controlBlock.containedType.dereference() == value->controlBlock.containedType);
		(*reinterpret_cast<MarshalledObject**> (pointer->data)) = value;
	}
}

MAP_TO_TYPE_DESCRIPTOR(cMCompiler::dataStructures::Variable*, cMCompiler::language::getVariableDescriptor, 0);
MAP_TO_TYPE_DESCRIPTOR(std::string, cMCompiler::language::getString, 0);
MAP_TO_TYPE_DESCRIPTOR(cMCompiler::dataStructures::SourcePointer, cMCompiler::language::getPointerToSource, 0);
