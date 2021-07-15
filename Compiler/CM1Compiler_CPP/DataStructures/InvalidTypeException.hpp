#pragma once
#include <exception>
#include "TypeReference.hpp"
#include "RuntimeException.hpp"

namespace cMCompiler::dataStructures
{
	class InvalidTypeException : public RuntimeException
	{
	public:
		InvalidTypeException(TypeReference const& expected, TypeReference const& recieved) :
			expected(expected),
			recieved(recieved),
			RuntimeException("Invalid type.") {}
		TypeReference const expected;
		TypeReference const recieved;
	};
}