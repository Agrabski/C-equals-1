#pragma once
#include <vector>
#include <string>
#include <memory>
#include "AttributeTarget.hpp"
#include "Type.hpp"
#include "IntermidiateRepresentation/VariableDeclaration.hpp"
#include "IntermidiateRepresentation/ScopeTermination.hpp"

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
		Type* const type_;
		std::string name_;
		ir::ScopeTermination* scopeTermination_;
		ir::VariableDeclaration* scopeStart_;
	public:
		void provideScope(ir::ScopeTermination* scopeTermination)
		{
			scopeTermination_ = scopeTermination;
		}
		void provideScope(ir::VariableDeclaration* scopeStart)
		{
			scopeStart_ = scopeStart;
		}
		Variable(std::string name, Type* type) : type_(type), name_(name) {}
		Type* type() noexcept { return type_; }
		std::string const& name() const noexcept { return name_; }
	};

}