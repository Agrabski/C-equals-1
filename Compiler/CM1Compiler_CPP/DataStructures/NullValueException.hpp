#pragma once
#include "RuntimeException.hpp"


namespace cMCompiler::dataStructures
{
	class NullValueException : public RuntimeException
	{
	public:
		NullValueException() : RuntimeException("Evaluation of expression did not produce a value.") {}

	};
}