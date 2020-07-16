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
		AttributeTarget(Target allowedTarget) noexcept : allowedTarget_(allowedTarget) {}
		AttributeInstance* appendAttribute(std::unique_ptr<AttributeInstance> attribute);

		std::vector<gsl::not_null<AttributeInstance*>> attributes();
		Target allowedTarget() const noexcept { return allowedTarget_; }
	};
}