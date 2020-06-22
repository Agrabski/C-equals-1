#pragma once
#include <vector>
#include <memory>
#include "AttributeInstance.hpp"


namespace cMCompiler::dataStructures
{
	enum class Target;
	class AttributeTarget
	{
		Target allowedTarget_;
		std::vector<std::unique_ptr<AttributeInstance>> attributes_;
	public:
		AttributeTarget(Target allowedTarget) : allowedTarget_(allowedTarget_) {}
		AttributeInstance* appendAttribute(std::unique_ptr<AttributeInstance> attribute);

		std::vector<AttributeInstance*> attributes();
	};
}