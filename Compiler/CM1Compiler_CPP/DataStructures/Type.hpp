#pragma once
#include <string>
#include <vector>
#include <gsl.h>
#include "INamedObject.hpp"
#include "Namespace.hpp"
#include "Function.hpp"
#include "ObjectWithAccessibility.hpp"
#include "AttributeTarget.hpp"
#include "TypeClassifier.hpp"

using gsl::not_null;

namespace cMCompiler::dataStructures
{
	class Namespace;
	class Field;
	class Type : public INamedObject, public ObjectWithAccessbility, public AttributeTarget
	{
		std::vector<std::unique_ptr<Function>> methods_;
		std::vector<std::unique_ptr<Field>> fields_;
		std::vector<Type*> implementedInterfaces_;
		TypeClassifier typeClassification_ = TypeClassifier::None;
	public:
		Type(std::string name, Namespace* parent, std::vector<Type*>& implementedInterfaces) :
			INamedObject(name, (INamedObject*)parent), implementedInterfaces_(implementedInterfaces),
			AttributeTarget(Target::Class)
		{}
		Type(std::string name, Namespace* parent) :
			INamedObject(name, (INamedObject*)parent),
			AttributeTarget(Target::Class)
		{}

		std::vector<not_null<Function*>> methods()
		{
			auto result = std::vector<gsl::not_null<Function*>>();
			for (auto& c : methods_)
				result.push_back(c.get());
			return result;
		}

		template<typename T>
		T* append(std::string n)
		{
			methods_.push_back(std::make_unique<T>(n, this));
			return methods_.back().get();
		}

		Type* setTypeClassifier(TypeClassifier t)
		{
			Expects(t != TypeClassifier::None);
			if (typeClassification_ != TypeClassifier::None)
				throw std::exception(); // todo: better exception
			typeClassification_ = t;
			return this;
		}

		std::vector<INamedObject*> children() final
		{
			auto result = std::vector<INamedObject*>();
			//for (auto& c : methods_)
			//	result.push_back(c.get());
			return result;
		}

		void appendInterface(Type*t)
		{
			implementedInterfaces_.push_back(t);
		}

		Field* appendField(std::string const& name, Type* type)
		{
			fields_.push_back(std::make_unique<Field>(name, type));
			return fields_.back().get();
		}

		std::vector<gsl::not_null<Field*>> fields()
		{
			auto result = std::vector<gsl::not_null<Field*>>();
			for (auto& c : fields_)
				result.push_back(c.get());
			return result;
		}

		// Inherited via INamedObject
		virtual std::vector<validation::ValidationError> validateContent() const override;
	};
}