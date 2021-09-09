#pragma once
#include <exception>
#include <vector>
#include <gsl/gsl>
#include "SourcePointer.hpp"

namespace cMCompiler::dataStructures
{
	class Function;
	struct stackFrame
	{
		gsl::not_null<Function*> function;
		SourcePointer currentInstruction;
	};

	class RuntimeException : public std::exception
	{
		std::vector<stackFrame> stackTrace_;
		std::string message_;
	public:
		RuntimeException() : std::exception() {}
		explicit RuntimeException(std::string msg) : std::exception(msg.c_str()), message_(std::move(msg)) {}
		void push(stackFrame&& frame);
		std::vector<stackFrame>const& trace() const noexcept;
	};
}
