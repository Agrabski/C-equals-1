#pragma once
#include <functional>

namespace cMCompiler::compiler
{
	void runWithHandling(std::function<void()> const& f);
}
