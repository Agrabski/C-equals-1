#pragma once
#include "INamedObject.hpp"
#include "AttributeTarget.hpp"
#include "TypeReference.hpp"
#include "Target.hpp"
#include "IValueHolder.hpp"
#include <vector>
#include <gsl/gsl>
#include <string>
#include <memory>
#include <variant>

using gsl::not_null;

namespace cMCompiler::dataStructures
{
	class INamedObject;
	class AttributeTarget;
	class Variable : public AttributeTarget, public INamedObject
	{
		std::unique_ptr<execution::IRuntimeValue> scopeBegin_;
		std::unique_ptr<execution::IRuntimeValue> scopeEnd_;
		TypeReference type_;
	public:
		void provideScopeBegin(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			scopeBegin_ = std::move(value);
		}
		void provideScopeEnd(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			scopeEnd_ = std::move(value);
		}

		Variable(std::string name, TypeReference type, not_null<Function*> parent, gsl::not_null<PackageDatabase*> p) :
			AttributeTarget(Target::Variable), INamedObject(name, (INamedObject*)parent.get(), p), type_(type){}
		TypeReference type() const noexcept;
		std::vector<validation::ValidationError> validateContent() const final { return {}; }
		std::vector<INamedObject*> children() final { return {}; };


		// Inherited via INamedObject
		execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;


		static constexpr auto onDeclare = "onDeclare";
		static constexpr auto onReference = "onReference";
	};

}