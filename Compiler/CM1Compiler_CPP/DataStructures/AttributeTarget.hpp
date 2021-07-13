#pragma once
#include <vector>
#include <memory>
#include <ranges>
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

		auto attributes() noexcept
		{
			return attributes_ | std::views::transform([](const auto& e) noexcept {return gsl::not_null(e.get()); });
		}
		auto attributes() const noexcept
		{
			return attributes_ | std::views::transform([](const auto& e)noexcept {return gsl::not_null(e.get()); });
		}
		Target allowedTarget() const noexcept { return allowedTarget_; }
		execution::json emmitAttributes(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const;
	};
}