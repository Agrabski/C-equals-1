#pragma once
#include <string>
#include <vector>
#include <gsl/gsl>
#include "INamedObject.hpp"
#include "Namespace.hpp"
#include "Function.hpp"
#include "ObjectWithAccessibility.hpp"
#include "AttributeTarget.hpp"
#include "TypeClassifier.hpp"
#include "Generic.hpp"
#include "GenericInstantiationData.hpp"
#include "MetadataObject.hpp"
#include "ObjectWithMetadata.hpp"

using gsl::not_null;

namespace cMCompiler::dataStructures
{
	enum TypeFlags : int64_t
	{
		None = 0b0,
		ExcludeAtRuntime = 0x1
	};

	TypeFlags operator|(TypeFlags lhs, TypeFlags rhs);
	TypeFlags operator&(TypeFlags lhs, TypeFlags rhs);

	struct TypeMetadata : public MetadataObject<TypeFlags, TypeFlags::None>
	{
	};

	class Namespace;
	class Field;
	class Type :
		public INamedObject,
		public ObjectWithAccessbility,
		public AttributeTarget,
		public InstantiationDataHolder<Type>,
		public ObjectWithMetadata<TypeMetadata>
	{
		std::vector<std::unique_ptr<Function>> methods_;
		std::vector<std::unique_ptr<Field>> fields_;
		std::vector<gsl::not_null<Type*>> implementedInterfaces_;
		std::vector<std::unique_ptr<Generic<Function>>> genericFunction_;

		TypeClassifier typeClassification_ = TypeClassifier::None;
	public:
		Type(std::string name, Namespace* parent, std::vector<gsl::not_null<Type*>>& implementedInterfaces, not_null<PackageDatabase*> p) :
			INamedObject(name, (INamedObject*)parent, p), implementedInterfaces_(implementedInterfaces),
			AttributeTarget(Target::Class)
		{}
		Type(std::string name, Namespace* parent, not_null<PackageDatabase*> p) :
			INamedObject(name, (INamedObject*)parent, p),
			AttributeTarget(Target::Class)
		{}

		TypeClassifier typeClassifier() const noexcept { return typeClassification_; }

		std::vector<not_null<Function*>> methods()
		{
			auto result = std::vector<gsl::not_null<Function*>>();
			for (auto& c : methods_)
				result.push_back(c.get());
			return result;
		}
		
		std::vector<not_null<Generic<Function>*>> genericMethods()
		{
			auto result = std::vector<gsl::not_null<Generic<Function>*>>();
			for (auto& c : genericFunction_)
				result.push_back(c.get());
			return result;
		}

		std::vector<not_null<Type*>> const& interfaces() const noexcept
		{
			return implementedInterfaces_;
		}

		template<typename T>
		T* append(std::string n)
		{
			methods_.push_back(std::make_unique<T>(n, this, package()));
			return methods_.back().get();
		}

		Type* setTypeClassifier(TypeClassifier t)
		{
			Expects(t != TypeClassifier::None);
			if (typeClassification_ != TypeClassifier::None && typeClassification_ != t)
				throw std::exception(); // todo: better exception
			typeClassification_ = t;
			return this;
		}

		std::vector<INamedObject*> children() noexcept final;

		void appendInterface(gsl::not_null<Type*> t)
		{
			implementedInterfaces_.push_back(t);
		}

		Function* getMethod(std::string const& name) noexcept
		{
			auto found = std::find_if(methods_.begin(), methods_.end(), [&](auto const& e) {return e->name() == name; });
			if (found != methods_.end())
				return found->get();
			return nullptr;
		}

		Field* appendField(std::string const& name, TypeReference type);

		std::vector<gsl::not_null<Field*>> fields()
		{
			auto result = std::vector<gsl::not_null<Field*>>();
			for (auto& c : fields_)
				result.push_back(c.get());
			return result;
		}

		template<typename T>
		gsl::not_null<Generic<T>*> appendGeneric(
			std::vector<std::string>&& parameterNames,
			std::unique_ptr<antlr4::tree::ParseTree>&& parseTree,
			std::string name,
			NameResolutionContext const& context,
			std::filesystem::path const& p)
		{
			auto tmp = std::make_unique<Generic<T>>(std::move(parameterNames), std::move(parseTree), name, this, context, p, package());
			not_null const result = tmp.get();
			genericFunction_.push_back(std::move(tmp));
			return result;
		}

		template<typename T>
		gsl::not_null<Generic<T>*> appendGeneric(
			std::vector<std::string>&& parameterNames,
			std::function<not_null<T*>(std::vector<TypeReference> const&)> customFill,
			std::string name,
			NameResolutionContext const& context,
			std::filesystem::path const& path)
		{
			auto tmp = std::make_unique<Generic<T>>(std::move(parameterNames), std::move(customFill), name, this, context, path, package());
			not_null const result = tmp.get();
			genericFunction_.push_back(std::move(tmp));
			return result;
		}


		// Inherited via INamedObject
		virtual std::vector<validation::ValidationError> validateContent() const override;

		// Inherited via INamedObject
		virtual execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const override;
	};
}