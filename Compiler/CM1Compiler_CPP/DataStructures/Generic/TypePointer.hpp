#pragma once
#include <variant>
#include "../Type.hpp"

namespace cMCompiler::dataStructures::generic
{
	class TypePointer
	{
	public:
		std::variant<not_null<Type*>, not_null<GenericParameter*>> const type_;
		TypePointer(std::variant<not_null<Type*>, not_null<GenericParameter*>> type) : type_(type) {}
	};
}