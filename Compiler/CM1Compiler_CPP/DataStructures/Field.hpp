#pragma once
#include "AttributeTarget.hpp"
#include "ObjectWithAccessibility.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
	class AttributeTarget;
	class Field : public AttributeTarget, public ObjectWithAccessbility
	{
		Type* const type_;
		std::string name_;
	public:
		Field(std::string name, Type* type) : type_(type), name_(name) {}
		Type* type() noexcept { return type_; }
		std::string const& name() const noexcept { return name_; }
	};

}