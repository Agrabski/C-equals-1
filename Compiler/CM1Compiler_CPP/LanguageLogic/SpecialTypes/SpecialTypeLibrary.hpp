#pragma once
#include <optional>
#include <map>
#include "../../DataStructures/Function.hpp"

namespace cMCompiler::language::specialTypes
{
	class SpecialTypeLibrary
	{
		std::map<dataStructures::Type*, std::string> typeMap_;
	public:
		static SpecialTypeLibrary& instance();
		void append(dataStructures::Type* type, std::string const& replaceWith);
	};
}