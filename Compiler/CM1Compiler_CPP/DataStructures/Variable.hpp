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
		std::unique_ptr<execution::IRuntimeValue> scopeBegin_;
		std::unique_ptr<execution::IRuntimeValue> scopeEnd_;
		not_null<Type*> type_;
	public:
		void provideScopeBegin(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			scopeBegin_ = std::move(value);
		}
		void provideScopeEnd(std::unique_ptr<execution::IRuntimeValue>&& value)
		{
			scopeEnd_ = std::move(value);
		}

		Variable(std::string name, not_null<Type*> type, not_null<Function*> parent, unsigned char referenceLevel) :
			AttributeTarget(Target::Variable), INamedObject(name, (INamedObject*)parent.get()), type_(type), IValueHolder(referenceLevel) {}
		not_null<Type*> type() noexcept;
		std::vector<validation::ValidationError> validateContent() const final { return {}; }
		std::vector<INamedObject*> children() final { return {}; };

	};

}