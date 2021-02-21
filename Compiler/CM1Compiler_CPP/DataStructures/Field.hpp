#pragma once
#include <gsl.h>
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
		public INamedObject,
		public IValueHolder
	{
		Type* const type_;
		std::vector<validation::ValidationError> validateContent() const final
		{
			return std::vector<validation::ValidationError>();
		}

		std::vector<INamedObject*> children() final { return {}; }

	public:
		Field(std::string name, Type* type, unsigned char referenceLevel, gsl::not_null<Type*> parent)
			: INamedObject(name, (INamedObject*)parent.get()),
			AttributeTarget(Target::Variable), type_(type),
			IValueHolder(referenceLevel) {}
		Type* type() noexcept { return type_; }
	};

}