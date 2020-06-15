#pragma once
#include "AttributeTarget.hpp"
#include "Variable.hpp"
#include "Type.hpp"
#include "INamedObject.hpp"
#include "Accessibility.hpp"
#include "IntermidiateRepresentation/IInstruction.hpp"
#include "ObjectWithAccessibility.hpp"

namespace cMCompiler::dataStructures
{
	class Function : public INamedObject, public AttributeTarget, public ObjectWithAccessbility
	{
		std::vector<std::unique_ptr<ir::IInstruction>> intermidiateRepresentation_;
		std::vector<std::unique_ptr<Variable>> parameters_;
		Type* returnType_;
	public:
		virtual ~Function() = default;
		Function(std::string name, INamedObject* parent) : INamedObject(name, parent) {}
		Variable* appendVariable(std::string name, Type* type);
		std::vector<Variable*> parameters();
		std::vector<INamedObject*> children() noexcept final
		{
			return std::vector<INamedObject*>();
		};
		void setReturnType(Type* t) { returnType_ = t; }
		Type* returnType() noexcept { return returnType_; }
	};
}
