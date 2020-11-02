#pragma once
#include <string>
#include <memory>
#include <gsl.h>
#include "Type.hpp"
#include "Function.hpp"
#include "INamedObject.hpp"
#include "ObjectWithAccessibility.hpp"
#include "Field.hpp"
#include "Target.hpp"
#include "Namespace.hpp"
#include "Generic.hpp"
#include "execution/ObjectValue.hpp"

using gsl::not_null;

namespace cMCompiler::dataStructures
{
	class Function;
	class Type;
	class Namespace;

	class Attribute : public INamedObject, public ObjectWithAccessbility
	{
		std::unique_ptr<Type> describingType_;
		Target attributeTarget_;
	public:
		Attribute(std::string name, Namespace* parent);
		void addAttributeTarget(Target t) noexcept { attributeTarget_ = attributeTarget_ | t; }
		bool targetValid(Target t) noexcept { return (attributeTarget_ & t) != Target::None; }
		std::vector<INamedObject*> children() final;

		std::vector<validation::ValidationError> validateContent() const final
		{
			return std::vector<validation::ValidationError>();
		}

		not_null<Field*> appendField(std::string const& name, Type* type);
		Function* appendFunction(std::string const& name);

		std::vector<gsl::not_null<Function*>> methods();

		Type* describingType() noexcept { return describingType_.get(); }
		template<typename T>
		gsl::not_null<Generic<T>*> appendGeneric(std::vector<std::string>&& parameterNames, std::unique_ptr<antlr4::tree::ParseTree>&& parseTree, std::string name)
		{
			std::terminate();
			throw 0;
		}
	};
}
