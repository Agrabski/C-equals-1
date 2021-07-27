#pragma once
#include <ranges>
#include <optional>

namespace cMCompiler::utilities
{
	template<std::ranges::range T>
	bool any(T& r)
	{
		return r.begin() != r.end();
	}

	template<std::ranges::view Range, typename T = std::iterator_traits<std::ranges::iterator_t<Range>>::value_type>
	std::optional<T> first(Range& r)
	{
		if (any(r))
			return *r.begin();
		return {};
	}
}
