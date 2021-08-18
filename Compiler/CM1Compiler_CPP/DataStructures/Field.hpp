#pragma once
#include <gsl/gsl>
#include "IValueHolder.hpp"
#include "AttributeTarget.hpp"
#include "ObjectWithAccessibility.hpp"
#include "Target.hpp"
#include "INamedObject.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
	class AttributeTarget;
	class Field :
		public AttributeTarget,
		public ObjectWithAccessbility,
		public INamedObject
	{
		TypeReference const type_;
		std::vector<validation::ValidationError> validateContent() const final
		{
			return std::vector<validation::ValidationError>();
		}

		std::vector<INamedObject*> children() noexcept final { return {}; }

	public:
		Field(std::string name, TypeReference type, gsl::not_null<Type*> parent)
			: INamedObject(name, (INamedObject*)parent.get()),
			AttributeTarget(Target::Variable), type_(type) {}
		TypeReference const& type() const noexcept { return type_; }

		// Inherited via INamedObject
		execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
	};

}