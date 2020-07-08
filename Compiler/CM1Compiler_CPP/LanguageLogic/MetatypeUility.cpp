#include "MetatypeUility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"


using namespace cMCompiler::dataStructures::execution;
std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<dataStructures::Type*> value)
{
	return std::make_unique<RuntimeTypeDescriptor>(getTypeDescriptor(), value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<dataStructures::Function*> value)
{
	return std::make_unique<RuntimeFunctionDescriptor>(getTypeDescriptor(), value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<dataStructures::Field*> value)
{
	return std::make_unique<RuntimeFieldDescriptor>(getFieldDescriptor(), value);
}
