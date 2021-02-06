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
		not_null<Type*> type_;
		std::string name_;
		std::unique_ptr<execution::IRuntimeValue> scopeTermination_;
		std::unique_ptr<execution::IRuntimeValue> scopeStart_;
	public:
		void provideScopeBegin(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			scopeStart_ = std::move(value);
		}
		void provideScopeEnd(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			scopeTermination_ = std::move(value);
		}

		Variable(std::string name, not_null<Type*> type) : AttributeTarget(Target::Variable), type_(type), name_(name) {}
		not_null<Type*> type() noexcept;
		std::string const& name() const noexcept { return name_; }
		not_null<execution::ObjectValue*> object();
	};

}