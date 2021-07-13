#pragma once
#include <ranges>
#include <concepts>

namespace cMCompiler::utilities
{
	template<typename Element, typename Collection>
	concept typed_range = std::ranges::range<Collection> && requires(Collection & c) { { *begin(c)} ->std::same_as<Element&>; };
}
