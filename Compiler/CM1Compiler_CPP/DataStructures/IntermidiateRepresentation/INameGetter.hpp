#pragma once
#include <string>


namespace cMCompiler::dataStructures
{
	class Type;
	class Function;
	class Field;
	class Variable;
}
namespace cMCompiler::dataStructures::ir
{
	class INameGetter
	{
	public:
		virtual std::string get(TypeReference const& t) const = 0;
		virtual std::string get(Function const* t) const = 0;
		virtual std::string get(Field const* t) const = 0;
		virtual std::string get(Variable const* t) const = 0;
	};
}