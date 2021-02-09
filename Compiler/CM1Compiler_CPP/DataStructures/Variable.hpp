#pragma once
#include <vector>
#include <gsl.h>
#include <string>
#include <memory>
#include "AttributeTarget.hpp"
#include "Type.hpp"
#include "IntermidiateRepresentation/VariableDeclaration.hpp"
#include "IntermidiateRepresentation/ScopeTermination.hpp"
#include "Target.hpp"
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
	class Variable : public AttributeTarget
	{
		std::unique_ptr<execution::IRuntimeValue> object_;
		not_null<Type*> type_;
		std::string name_;
	public:
		void provideScopeBegin(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			dynamic_cast<execution::ObjectValue*>(object_.get())->setValue("_scopeStart", std::move(value));
		}
		void provideScopeEnd(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			dynamic_cast<execution::ObjectValue*>(object_.get())->setValue("_scopeTermination", std::move(value));
		}

		Variable(std::string name, not_null<Type*> type, std::function<std::unique_ptr<execution::IRuntimeValue>(not_null<Variable*>)> objectFactory) :
			AttributeTarget(Target::Variable), type_(type), name_(name), object_(objectFactory(this)) {}
		not_null<Type*> type() noexcept;
		std::string const& name() const noexcept { return name_; }
		not_null<execution::IRuntimeValue*> object() { return object_.get(); }
	};

}