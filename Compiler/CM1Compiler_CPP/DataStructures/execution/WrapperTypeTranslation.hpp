#pragma once
#include "RuntimeTypeDescriptor.hpp"
#include "RuntimeFunctionDescriptor.hpp"
#include "RuntimeFieldDescriptor.hpp"
#include "RuntimeVariableDescriptor.hpp"
#include "../Type.hpp"
#include "../TypeReference.hpp"
#include "../Function.hpp"
#include "../Variable.hpp"

namespace cMCompiler::dataStructures::execution
{
	template<typename T>
	struct WrapperTypeTranslation {};

#define DEFINE_WRAPPER(a, b) template<> struct WrapperTypeTranslation<a>\
{\
	using WrapperType = b;\
	char const * const TypeName = #b ;\
};

	DEFINE_WRAPPER(TypeReference, RuntimeTypeDescriptor);
	DEFINE_WRAPPER(Function, RuntimeFunctionDescriptor);
	DEFINE_WRAPPER(Field, RuntimeFieldDescriptor);
	DEFINE_WRAPPER(Variable, RuntimeVariableDescriptor);

	template<typename T>
	concept wrapped_type = std::derived_from<typename WrapperTypeTranslation<T>::WrapperType, IRuntimeValue>;
}