#pragma once
#include <string>
#include <vector>
#include "INamedObject.hpp"
#include "Namespace.hpp"
#include "Function.hpp"
#include "ObjectWithAccessibility.hpp"
#include "AttributeTarget.hpp"
#include "TypeClassifier.hpp"

namespace cMCompiler::dataStructures
{
	class Namespace;
	class Type : public INamedObject, public ObjectWithAccessbility, public AttributeTarget
	{
		std::vector<std::unique_ptr<Function>> methods_;
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
		std::vector<Function*> methods()
		{
			auto result = std::vector<Function*>();
			for (auto& c : methods_)
				result.push_back(c.get());
			return result;
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

		// Inherited via INamedObject
		virtual std::vector<validation::ValidationError> validateContent() const override;
	};
}