#pragma once
#include <string>
#include <vector>
#include <type_traits>

namespace cMCompiler::dataStructures
{
	enum class Target
	{
		None = 0,
		Class = 0b000001,
		Interface = 0b000010,
		Function = 0b000100,
		Struct = 0b001000,
		Variable = 0b010000,
		Enum = 0b100000,
		Any = 0b11111
	};
	inline Target operator | (Target lhs, Target rhs) noexcept
	{
		using T = std::underlying_type_t <Target>;
		return static_cast<Target>(static_cast<T>(lhs) | static_cast<T>(rhs));
	}
	inline Target operator & (Target lhs, Target rhs) noexcept
	{
		using T = std::underlying_type_t <Target>;
		return static_cast<Target>(static_cast<T>(lhs) & static_cast<T>(rhs));
	}

	inline Target& operator |= (Target& lhs, Target rhs) noexcept
	{
		lhs = lhs | rhs;
		return lhs;
	}

	Target parseTarget(std::vector<std::string> const& text);


}
