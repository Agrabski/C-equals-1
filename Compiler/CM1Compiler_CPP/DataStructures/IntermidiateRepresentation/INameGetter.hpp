#pragma once
#include <string>


namespace cMCompiler::dataStructures
{
	class Type;
	class Function;
}
namespace cMCompiler::dataStructures::ir
{
	class INameGetter
	{
	public:
		virtual std::string get(Type const* t) const = 0;
		virtual std::string get(Function const* t) const = 0;
	};
}