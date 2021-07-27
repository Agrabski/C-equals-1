#pragma once
#include <type_traits>
#include <memory>

namespace cMCompiler::utilities
{
	template<typename To, typename From>
	std::unique_ptr<To> pointer_cast(std::unique_ptr<From>&& ptr)
	{
		static_assert(std::is_assignable<To, From>::value);
		return std::unique_ptr<To>(ptr.release());
	}

	template<typename T>
	T* toPointer(T* t)
	{
		return t;
	}
	template<typename T>
	T* toPointer(T& t)
	{
		return &t;
	}
}
