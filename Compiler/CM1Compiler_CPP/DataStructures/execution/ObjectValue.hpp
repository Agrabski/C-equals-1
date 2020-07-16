#pragma once
#include <map>
#include <cassert>
#include "IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	class ObjectValue : public IRuntimeValue
	{
		std::map<std::string, std::unique_ptr<IRuntimeValue>> values_;
		// Inherited via IRuntimeValue
		virtual void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const override;
		virtual std::string toString() const override;
		bool validate(IRuntimeValue* value, std::string const& name);
	public:
		ObjectValue(Type* t) noexcept : IRuntimeValue(t) 
		{
		}

		std::unique_ptr<IRuntimeValue>& getMemberValue(std::string const& name)
		{
			return values_[name];
		}

		Type* getMemberType(std::string const& name);

		void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value)
		{
			assert(validate(value.get(), name));
			values_[name] = std::move(value);
		}

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;
	};
}