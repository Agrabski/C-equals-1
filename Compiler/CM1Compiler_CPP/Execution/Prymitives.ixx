module;

#include "../Utilities/compilation_shim.hpp"
export module Execution.Prymitives;
import Execution.Marshalling;
import <gsl/gsl>;

namespace cMCompiler::execution
{
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
}
