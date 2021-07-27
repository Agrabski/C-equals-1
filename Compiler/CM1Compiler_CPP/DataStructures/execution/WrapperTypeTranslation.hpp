#pragma once
#include "RuntimeTypeDescriptor.hpp"
#include "RuntimeFunctionDescriptor.hpp"
#include "../Type.hpp"
#include "../TypeReference.hpp"
#include "../Function.hpp"

namespace cMCompiler::dataStructures::execution
{
	template<typename T>
	struct WrapperTypeTranslation {};

#define DEFINE_WRAPPER(a, b) template<> struct WrapperTypeTranslation<a> {using WrapperType = b;};

	DEFINE_WRAPPER(TypeReference, RuntimeTypeDescriptor);
	DEFINE_WRAPPER(Function, RuntimeFunctionDescriptor);

	template<typename T>
	concept wrapped_type = std::derived_from<typename WrapperTypeTranslation<T>::WrapperType, IRuntimeValue>;
}