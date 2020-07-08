#include "Target.hpp"
#include <map>

using namespace cMCompiler::dataStructures;
Target cMCompiler::dataStructures::parseTarget(std::vector<std::string>const& text)
{
	using namespace std::string_literals;
	static std::map<std::string, Target> map =
	{
		{"type"s, Target::Class | Target::Interface | Target::Interface},
		{"function"s, Target::Function},
		{"variable", Target::Variable}
	};
	Target result = Target::None;
	for (auto const& t : text)
	{
		auto found = map.find(t);
		if (found != map.end())
			result |= found->second;
	}
	return result;
}
