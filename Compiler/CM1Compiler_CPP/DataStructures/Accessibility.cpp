#include "Accessibility.hpp"

using namespace cMCompiler::dataStructures;

Accessibility cMCompiler::dataStructures::parse(std::string const& text)
{
	static std::map<std::string, Accessibility> accesibilityMap =
	{
		{"public", Accessibility::Public},
		{"private", Accessibility::Private},
		{"protected", Accessibility::Protected},
		{"", Accessibility::Private}
	};
	auto result = accesibilityMap.find(text);
	if (result != accesibilityMap.end())
		return result->second;
	throw AccessbilityParseException(text);
}
