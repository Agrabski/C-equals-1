#pragma once
#include <string>
#include <vector>
#include "QualifiedName.hpp"
#include "execution/ObjectValue.hpp"
#include "Validation/ValidationError.hpp"

namespace cMCompiler::dataStructures
{
	enum class ObjectState { Cretated, Confirmed, Finalized };
	class INamedObject
	{
		std::unique_ptr<execution::IRuntimeValue> sourcePointer_;
		std::string name_;
		INamedObject* parent_;
		INamedObject(INamedObject&&) = delete;
		ObjectState state_ = ObjectState::Cretated;
	protected:
		INamedObject(std::string name, INamedObject* parent)
			: name_(name), parent_(parent) {}
		virtual std::vector<validation::ValidationError> validateContent() const = 0;
	public:
		ObjectState state() const noexcept { return state_; }
		void confirm() noexcept { if (state_ == ObjectState::Cretated) state_ = ObjectState::Confirmed; }
		void finalize() noexcept { state_ = ObjectState::Finalized; }
		virtual ~INamedObject() = default;
		std::string const& name() const noexcept { return name_; }
		std::string & name() noexcept { return name_; }
		INamedObject* parent() const noexcept { return parent_; }
		QualifiedName qualifiedName() const;
		virtual std::vector<INamedObject*> children() = 0;
		virtual execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const = 0;
		std::vector<validation::ValidationError> validate() const;
		void setSourceLocation(std::unique_ptr<execution::IRuntimeValue>&& sourceLocation) noexcept
		{
			sourcePointer_ = std::move(sourceLocation);
		}
		std::unique_ptr<execution::IRuntimeValue> sourcePointer() const
		{
			return sourcePointer_->copy();
		}
	};
}
