#pragma once
#include <vector>
#include <memory>
#include "AttributeInstance.hpp"

namespace cMCompiler::dataStructures
{
	class AttributeTarget
	{
		std::vector<std::unique_ptr<AttributeInstance>> attributes_;
	public:
		AttributeInstance* appendAttribute(std::unique_ptr<AttributeInstance> attribute);

		std::vector<AttributeInstance*> attributes();
	};
}