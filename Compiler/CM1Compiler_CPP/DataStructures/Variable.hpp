#pragma once
#include <vector>
#include <string>
#include <memory>
#include "AttributeTarget.hpp"
#include "Type.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
	class AttributeTarget;
	class Variable : public AttributeTarget
	{
		Type* const type_;
		std::string name_;
	public:
		Variable(std::string name, Type* type) : type_(type), name_(name) {}
		Type* type() noexcept { return type_; }
		std::string const& name() const noexcept { return name_; }
	};

}