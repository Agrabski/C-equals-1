#pragma once
#include <algorithm>
#include <vector>

namespace cMCompiler::utilities
{
	template<typename T, typename F>
	typename T::iterator find_if(T&v, F f)
	{
		return std::find_if(begin(v), end(v), f);
	}
}