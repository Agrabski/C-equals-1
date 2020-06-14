#pragma once
#include <exception>
#include <string>
#include <map>

namespace cMCompiler::dataStructures
{
	enum class Accessibility
	{
		Public,
		Private,
		Protected
	};

	using namespace std::literals;

	class AccessbilityParseException : std::exception
	{

	public:
		AccessbilityParseException(std::string text) : text_(text) {}
		std::string const text_;
	};

	Accessibility parse(std::string const& text);
}
