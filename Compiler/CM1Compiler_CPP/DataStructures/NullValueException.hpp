#pragma once
#include "RuntimeException.hpp"


namespace cMCompiler::dataStructures
{
	class NullValueException : RuntimeException
	{
	public:
		explicit NullValueException() : RuntimeException("Evaluation of expression did not produce a value.") {}

	};
}