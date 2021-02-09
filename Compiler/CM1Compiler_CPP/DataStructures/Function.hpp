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
#include "execution/ArrayValue.hpp"

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
		std::unique_ptr<execution::ArrayValue> intermidiateRepresentation_;
		std::vector<std::unique_ptr<Variable>> parameters_;
		std::vector<std::unique_ptr<Variable>> localVariables_;
		Type* returnType_ = nullptr;
	public:
		virtual ~Function() = default;
		Function(std::string name, INamedObject* parent)
			: AttributeTarget(Target::Function), INamedObject(name, parent) {}
		Variable* appendVariable(std::string name, not_null<Type*> type, std::function<std::unique_ptr<execution::IRuntimeValue>(not_null<Variable*>)> objectFactory);
		Variable* appendLocalVariable(std::string name, not_null<Type*> type, std::function<std::unique_ptr<execution::IRuntimeValue>(not_null<Variable*>)> objectFactory);
		std::vector<Variable*> parameters();
		std::vector<INamedObject*> children() noexcept final
		{
			return std::vector<INamedObject*>();
		};
		not_null<Function*> setReturnType(Type* t) noexcept
		{
			returnType_ = t;
			return this;
		}

		void setIrCollection(std::unique_ptr<execution::ArrayValue>&& collection)
		{
			intermidiateRepresentation_ = std::move(collection);
		}
		Type* returnType() noexcept { return returnType_; }
		std::unique_ptr<execution::ArrayValue>& code() noexcept { return intermidiateRepresentation_; }
		void pushInstruction(std::unique_ptr<execution::IRuntimeValue>&& instruction)
		{
			intermidiateRepresentation_->push(std::move(instruction));
		}

		// Inherited via INamedObject
		std::vector<validation::ValidationError> validateContent() const final;
	};
}
