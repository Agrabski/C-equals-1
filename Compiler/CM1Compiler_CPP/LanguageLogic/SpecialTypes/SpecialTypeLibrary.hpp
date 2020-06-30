#pragma once
#include <optional>
#include "../../DataStructures/Function.hpp"

namespace cMCompiler::language::specialTypes
{
	class SpecialTypeLibrary
	{
	public:
		static SpecialTypeLibrary& instance();
		void append(dataStructures::Type* type, std::string const& replaceWith);
	};
}