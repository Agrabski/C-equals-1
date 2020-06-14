#pragma once
#include <vector>
#include <string>
#include <memory>
#include "AttributeInstance.hpp"
#include "Type.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
	class Variable
	{
		Type* const type_;
		std::string name_;
		std::vector<std::unique_ptr<AttributeInstance>> attributes_;
	public:
		Variable(std::string name, Type* type);
	};

}