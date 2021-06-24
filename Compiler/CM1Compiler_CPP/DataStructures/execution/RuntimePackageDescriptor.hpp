#pragma once
#include "IRuntimeValue.h"
#include "../Function.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"


namespace cMCompiler::dataStructures::execution
{
	class RuntimePackageDescriptor : public IRuntimeValue
	{
		PackageDatabase * value_;
		// Inherited via IRuntimeValue
		std::string typeName() const final
		{
			return "runtime_package_descriptor";
		}
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
	public:
		RuntimePackageDescriptor(TypeReference descriptorType, PackageDatabase * const value) noexcept : IRuntimeValue(descriptorType), value_(value) {}
		PackageDatabase * value() const noexcept { return value_; }
		std::string toString() const final;

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;
		virtual ~RuntimePackageDescriptor() = default;
	};
}
