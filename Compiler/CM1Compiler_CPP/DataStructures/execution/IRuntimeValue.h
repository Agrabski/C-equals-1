#pragma once
#include <functional>
#include <ostream>
#include "../TypeReference.hpp"
#include "../../Utilities/json.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"
#include "../ISerializationManager.hpp"

namespace cMCompiler::dataStructures::execution
{
	using json = nlohmann::json;
	class IRuntimeValue
	{
		TypeReference type_;
	protected:
		virtual std::string typeName() const = 0;
		virtual json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const = 0;
	public:
		IRuntimeValue(TypeReference type) noexcept: type_(type)
		{}
		json serialize(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const noexcept;
		TypeReference const& type() const noexcept { return type_; }
		virtual std::string toString() const = 0;
		virtual std::unique_ptr<IRuntimeValue> copy() const = 0;

	};
}
