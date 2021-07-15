#pragma once
#include "RuntimeException.hpp"
#include <ostream>

namespace cMCompiler::dataStructures
{
	void printStackTrace(std::vector<stackFrame> const& stack, std::ostream& stream);
}