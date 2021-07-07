#pragma once
#include <exception>
#include <vector>
#include <gsl.h>
#include "Function.hpp"
#include "SourcePointer.hpp"

namespace cMCompiler::dataStructures
{
	struct stackFrame
	{
		gsl::not_null<Function*> function;
		SourcePointer currentInstruction;
	};

	class RuntimeException : public std::exception
	{
		std::vector<stackFrame> stackTrace_;
	public:
		RuntimeException() : std::exception() {}
		explicit RuntimeException(char const* msg) : std::exception(msg) {}
		void push(stackFrame&& frame);
		std::vector<stackFrame>const& trace() const noexcept;
	};
}
