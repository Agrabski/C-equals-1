#include "MetatypeUility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "LiteralUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "../DataStructures/Namespace.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"


using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;

std::unique_ptr<ObjectValue> cMCompiler::language::buildObjectFor(gsl::not_null<Type*> type)
{
	using namespace cMCompiler::language;
	using namespace std::string_literals;
	auto result = std::make_unique<ObjectValue>(getTypeDescriptor());
	result->setValue("name"s, buildStringValue(type->name()));
	result->setValue("qualifiedName"s, buildStringValue((std::string)type->qualifiedName()));
	result->setValue("parent"s, std::make_unique<ReferenceValue>(type->parent()->object(), getNamespaceDescriptor()));
	return result;
}

void cMCompiler::language::supplyValueTo(gsl::not_null<dataStructures::ir::ScopeTermination*> st)
{
}
void cMCompiler::language::supplyValueTo(gsl::not_null<dataStructures::ir::VariableDeclaration*> st)
{
}
void cMCompiler::language::supplyValueTo(gsl::not_null<dataStructures::ir::IfElseStatement*> st)
{
}
void cMCompiler::language::supplyValueTo(gsl::not_null<dataStructures::ir::FunctionCall*> st)
{
}
void cMCompiler::language::supplyValueTo(gsl::not_null<dataStructures::ir::AssigmentStatement*> st)
{
}

std::unique_ptr<ObjectValue> cMCompiler::language::buildObjectFor(gsl::not_null<Namespace*> ns)
{
	using namespace cMCompiler::language;
	using namespace std::string_literals;
	auto result = std::make_unique<ObjectValue>(getTypeDescriptor());
	result->setValue("name"s, buildStringValue(ns->name()));
	result->setValue("qualifiedName"s, buildStringValue((std::string)ns->qualifiedName()));
	return result;

}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<Type*> value)
{
	return std::make_unique<RuntimeTypeDescriptor>(getTypeDescriptor(), value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<Function*> value)
{
	return std::make_unique<RuntimeFunctionDescriptor>(getTypeDescriptor(), value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<Field*> value)
{
	return std::make_unique<RuntimeFieldDescriptor>(getFieldDescriptor(), value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::buildPointerToSource(std::string const& filename, unsigned long long lineNumber)
{

	auto result = instantiate(getPointerToSource());
	auto& object = dynamic_cast<ObjectValue&>(*result);
	object.setValue("filename", buildStringValue(filename));
	object.setValue("lineNumber", buildIntegerValue(getUsize(), reinterpret_cast<number_component*>(&lineNumber), sizeof(lineNumber)));
	return result;
}
