#include "MetatypeUility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "LiteralUtility.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"


using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;

std::unique_ptr<ObjectValue>  cMCompiler::language::buildObjectFor(gsl::not_null<Type*> type)
{
	using namespace cMCompiler::language;
	using namespace std::string_literals;
	auto result = std::make_unique<ObjectValue>(getTypeDescriptor());
	result->setValue("name"s, buildStringValue(type->name()));
	result->setValue("qualifiedName"s, buildStringValue((std::string)type->qualifiedName()));
	return result;
}


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
