#pragma once
#include <string>
#include <vector>
#include <type_traits>

namespace cMCompiler::dataStructures
{
	enum class Target
	{
		None = 0,
		Class = 0b00001,
		Interface = 0b00010,
		Function = 0b00100,
		Struct = 0b01000,
		Variable = 0b10000,
		Any = 0b11111
	};
	inline Target operator | (Target lhs, Target rhs)
	{
		using T = std::underlying_type_t <Target>;
		return static_cast<Target>(static_cast<T>(lhs) | static_cast<T>(rhs));
	}
	inline Target operator & (Target lhs, Target rhs)
	{
		using T = std::underlying_type_t <Target>;
		return static_cast<Target>(static_cast<T>(lhs) & static_cast<T>(rhs));
	}

	inline Target& operator |= (Target& lhs, Target rhs)
	{
		lhs = lhs | rhs;
		return lhs;
	}

	Target parseTarget(std::vector<std::string> const& text);


}
