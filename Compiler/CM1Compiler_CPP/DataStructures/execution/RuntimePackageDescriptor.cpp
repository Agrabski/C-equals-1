#include "RuntimePackageDescriptor.hpp"
#include <memory>
#include "../PackageDatabase.hpp"

using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::RuntimePackageDescriptor::copy() const
{
	return std::make_unique<RuntimePackageDescriptor>(type(), value_);
}

std::string cMCompiler::dataStructures::execution::RuntimePackageDescriptor::toString() const
{
	return "{package: " + value_->name() + "}";
}

json cMCompiler::dataStructures::execution::RuntimePackageDescriptor::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		"value", value_->name()
	};
}
