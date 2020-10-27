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
		execution::ObjectValue* acutalObject_ = nullptr;
		std::unique_ptr<execution::IRuntimeValue> corespondingObject_;
		std::string name_;
		INamedObject* parent_;
		INamedObject(INamedObject&&) = delete;
		ObjectState state_ = ObjectState::Cretated;
	protected:
		INamedObject(std::string name, INamedObject* parent)
			: name_(name), parent_(parent) {}
		virtual std::vector<validation::ValidationError> validateContent() const = 0;
	public:
		void setObject(std::unique_ptr<execution::ObjectValue>&& value)
		{
			assert(corespondingObject_ == nullptr);
			acutalObject_ = value.get();
			corespondingObject_ = std::move(value);
		}
		execution::ObjectValue* acutalObject() noexcept { return acutalObject_; }
		std::unique_ptr<execution::IRuntimeValue>* object() noexcept { return &corespondingObject_; }
		ObjectState state() const noexcept { return state_; }
		void confirm() noexcept { if (state_ == ObjectState::Cretated) state_ = ObjectState::Confirmed; }
		void finalize() noexcept { state_ = ObjectState::Finalized; }
		virtual ~INamedObject() = default;
		std::string const& name() const noexcept { return name_; }
		INamedObject* parent() const noexcept { return parent_; }
		QualifiedName qualifiedName() const;
		virtual std::vector<INamedObject*> children() = 0;
		std::vector<validation::ValidationError> validate() const;
	};
}
