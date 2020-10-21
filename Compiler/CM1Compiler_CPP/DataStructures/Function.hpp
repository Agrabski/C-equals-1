#pragma once
#include <ostream>
#include <istream>
#include "IntermidiateRepresentation/IInstruction.hpp"
#include "AttributeTarget.hpp"
#include "Variable.hpp"
#include "Type.hpp"
#include "INamedObject.hpp"
#include "Accessibility.hpp"
#include "ObjectWithAccessibility.hpp"
#include "Target.hpp"
#include "ObjectWithMetadata.hpp"
#include "MetadataObject.hpp"

using gsl::not_null;

namespace cMCompiler::ir
{
	class IInstruction;
}

namespace cMCompiler::dataStructures
{
	enum class FunctionFlags
	{
		None = 0b0000000000000,
		ExcludeAtCompileTime = 0b0000000000001,
		ExcludeAtRuntimeTime = 0b0000000000010,
		Unsafe = 0b0000000000100
	};

	FunctionFlags operator|(FunctionFlags lhs, FunctionFlags rhs);
	FunctionFlags operator&(FunctionFlags lhs, FunctionFlags rhs);

	struct FunctionMetadata : public MetadataObject<FunctionFlags, FunctionFlags::None>
	{
	};

	std::ostream& operator<<(std::ostream& stream, FunctionFlags flags);
	std::istream& operator>>(std::istream& stream, FunctionFlags& flags);

	class Variable;
	class Type;

	class Function :
		public INamedObject,
		public AttributeTarget,
		public ObjectWithAccessbility,
		public ObjectWithMetadata<FunctionMetadata>
	{
		std::vector<std::unique_ptr<ir::IInstruction>> intermidiateRepresentation_;
		std::vector<std::unique_ptr<Variable>> parameters_;
		std::vector<std::unique_ptr<Variable>> localVariables_;
		Type* returnType_;
	public:
		virtual ~Function() = default;
		Function(std::string name, INamedObject* parent)
			: AttributeTarget(Target::Function), INamedObject(name, parent) {}
		Variable* appendVariable(std::string name, not_null<Type*> type);
		Variable* appendLocalVariable(std::string name, not_null<Type*> type);
		std::vector<Variable*> parameters();
		std::vector<INamedObject*> children() noexcept final
		{
			return std::vector<INamedObject*>();
		};
		void setReturnType(Type* t) noexcept { returnType_ = t; }
		Type* returnType() noexcept { return returnType_; }
		std::vector<ir::IInstruction*> code();
		void pushInstruction(std::unique_ptr<ir::IInstruction>&& instruction)
		{
			intermidiateRepresentation_.push_back(std::move(instruction));
		}

		// Inherited via INamedObject
		std::vector<validation::ValidationError> validateContent() const final;
	};
}
