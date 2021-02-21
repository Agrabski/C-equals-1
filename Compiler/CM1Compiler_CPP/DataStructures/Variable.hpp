#pragma once
#include "INamedObject.hpp"
#include "AttributeTarget.hpp"
#include "Type.hpp"
#include "Target.hpp"
#include "IValueHolder.hpp"
#include <vector>
#include <gsl.h>
#include <string>
#include <memory>
#include <variant>

using gsl::not_null;

namespace cMCompiler::dataStructures
{
	namespace ir
	{
		class ScopeTermination;
		class VariableDeclaration;
	}
	class Type;
	class AttributeTarget;
	class Variable : public AttributeTarget, public INamedObject, public IValueHolder
	{
		std::unique_ptr<execution::IRuntimeValue> object_;
		not_null<Type*> type_;
	public:
		void provideScopeBegin(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			dynamic_cast<execution::ObjectValue*>(object_.get())->setValue("_scopeStart", std::move(value));
		}
		void provideScopeEnd(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			dynamic_cast<execution::ObjectValue*>(object_.get())->setValue("_scopeTermination", std::move(value));
		}

		Variable(std::string name, not_null<Type*> type, not_null<Function*> parent, unsigned char referenceLevel, std::function<std::unique_ptr<execution::IRuntimeValue>(not_null<Variable*>)> objectFactory) :
			AttributeTarget(Target::Variable), INamedObject(name, (INamedObject*)parent.get()), type_(type), object_(objectFactory(this)), IValueHolder(referenceLevel) {}
		not_null<Type*> type() noexcept;
		not_null<execution::IRuntimeValue*> object() { return object_.get(); }
		std::vector<validation::ValidationError> validateContent() const final { return {}; }
		std::vector<INamedObject*> children() final { return {}; };

	};

}