#pragma once
#include <string>
#include <ostream>
#include <istream>
#include <optional>
#include "AttributeTarget.hpp"
#include "Variable.hpp"
#include "Type.hpp"
#include "INamedObject.hpp"
#include "Accessibility.hpp"
#include "ObjectWithAccessibility.hpp"
#include "Target.hpp"
#include "ObjectWithMetadata.hpp"
#include "MetadataObject.hpp"
#include "GenericInstantiationData.hpp"
#include "execution/ArrayValue.hpp"

using gsl::not_null;

namespace cMCompiler::ir
{
	class IInstruction;
}

namespace cMCompiler::dataStructures
{
	enum class FunctionFlags : int64_t
	{
		None = 0b0000000000000,
		ExcludeAtCompileTime = 0b0000000000001,
		ExcludeAtRuntime = 0b0000000000010,
		Unsafe = 0b0000000000100
	};

	FunctionFlags operator|(FunctionFlags lhs, FunctionFlags rhs);
	FunctionFlags operator&(FunctionFlags lhs, FunctionFlags rhs);

	struct FunctionMetadata : public MetadataObject<FunctionFlags, FunctionFlags::None>
	{
		std::optional<std::string> overrideLLVMIR_;
	};

	std::ostream& operator<<(std::ostream& stream, FunctionFlags flags);
	std::istream& operator>>(std::istream& stream, FunctionFlags& flags);

	class Variable;

	class Function :
		public INamedObject,
		public AttributeTarget,
		public ObjectWithAccessbility,
		public ObjectWithMetadata<FunctionMetadata>,
		public InstantiationDataHolder<Function>
	{
		std::unique_ptr<execution::ArrayValue> intermidiateRepresentation_;
		std::vector<std::unique_ptr<Variable>> parameters_;
		std::vector<std::unique_ptr<Variable>> localVariables_;
		TypeReference returnType_;
	public:
		virtual ~Function() = default;
		Function(std::string name, INamedObject* parent)
			: AttributeTarget(Target::Function), INamedObject(name, parent) {}
		not_null<Variable*> appendVariable(std::string name, TypeReference type);
		not_null<Variable*> appendLocalVariable(std::string name, TypeReference type);
		std::vector<not_null<Variable*>> parameters();
		std::vector<not_null<Variable*>> variables() const;
		std::vector<not_null<Variable const*>> parameters() const;
		std::vector<INamedObject*> children() noexcept final
		{
			return std::vector<INamedObject*>();
		};
		not_null<Function*> setReturnType(TypeReference t) noexcept
		{
			returnType_ = t;
			return this;
		}

		void setIrCollection(std::unique_ptr<execution::ArrayValue>&& collection) noexcept
		{
			intermidiateRepresentation_ = std::move(collection);
		}
		TypeReference returnType() const noexcept { return returnType_; }
		std::unique_ptr<execution::ArrayValue>& code() noexcept { return intermidiateRepresentation_; }
		void pushInstruction(std::unique_ptr<execution::IRuntimeValue>&& instruction) const
		{
			intermidiateRepresentation_->push(std::move(instruction));
		}

		// Inherited via INamedObject
		std::vector<validation::ValidationError> validateContent() const final;
		execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
	};
}
