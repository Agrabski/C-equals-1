#pragma once
#include <string>
#include <memory>
#include <gsl/gsl>
#include "Type.hpp"
#include "Function.hpp"
#include "INamedObject.hpp"
#include "ObjectWithAccessibility.hpp"
#include "Field.hpp"
#include "Target.hpp"
#include "Namespace.hpp"
#include "Generic.hpp"
#include "execution/ObjectValue.hpp"
#include "NameResolutionContext.hpp"
#include "../Parser/antlr4-runtime.h"

using gsl::not_null;

namespace cMCompiler::dataStructures
{
	class Function;
	class Type;
	class Namespace;
	template<typename T>
	class Generic;

	class Attribute : public INamedObject, public ObjectWithAccessbility
	{
		std::unique_ptr<Type> describingType_;
		Target attributeTarget_ = Target::None;
	public:
		Attribute(std::string name, Namespace* parent);
		void addAttributeTarget(Target t) noexcept { attributeTarget_ = attributeTarget_ | t; }
		bool targetValid(Target t) noexcept { return (attributeTarget_ & t) != Target::None; }
		std::vector<INamedObject*> children() final;

		std::vector<validation::ValidationError> validateContent() const noexcept final
		{
			return std::vector<validation::ValidationError>();
		}

		not_null<Field*> appendField(std::string const& name, TypeReference type);
		Function* appendFunction(std::string const& name);

		std::vector<gsl::not_null<Function*>> methods();

		Type * describingType() noexcept { return describingType_.get(); }
		template<typename T>
		gsl::not_null<Generic<T>*> appendGeneric(
			std::vector<std::string>&& parameterNames, 
			std::unique_ptr<antlr4::tree::ParseTree>&& parseTree, 
			std::string name,
			NameResolutionContext const&,
			std::filesystem::path const&)
		{
			std::terminate();
			throw 0;
		}



		execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;

	};
}
