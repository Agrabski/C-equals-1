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
		ir::ScopeTermination* scopeTermination_;
		ir::VariableDeclaration* scopeStart_;
	public:
		void provideScope(not_null<ir::ScopeTermination*> scopeTermination) noexcept
		{
			scopeTermination_ = scopeTermination;
		}
		void provideScope(not_null<ir::VariableDeclaration*> scopeStart) noexcept
		{
			scopeStart_ = scopeStart;
		}
		Variable(std::string name, not_null<Type*> type) : AttributeTarget(Target::Variable), type_(type), name_(name) {}
		not_null<Type*> type() noexcept;
		std::string const& name() const noexcept { return name_; }
	};

}