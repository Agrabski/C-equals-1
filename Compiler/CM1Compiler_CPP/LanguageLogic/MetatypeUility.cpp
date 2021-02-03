#include "MetatypeUility.hpp"
#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "LiteralUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "../DataStructures/Namespace.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"
#include "RuntimeTypesConversionUtility.hpp"


using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;

gsl::not_null<ObjectValue*> castToObject(cMCompiler::language::runtime_value& value)
{
	return dynamic_cast<ObjectValue*>(value.get());
}

gsl::not_null<ArrayValue*> castToArray(gsl::not_null<ReferenceValue*> reference)
{
	return dynamic_cast<ArrayValue*>(reference->value()->get());
}

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

void cMCompiler::language::suplyParent(runtime_value& instruction, runtime_value&& referenceToParent)
{
	auto object = castToObject(instruction);
	assert(canCastReference(referenceToParent->type(), object->getMemberType("_parent")));
	object->setValue("_parent", std::move(referenceToParent));
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

cMCompiler::language::runtime_value cMCompiler::language::buildAssigmentStatement(runtime_value&& lExpression, runtime_value&& rExpression, runtime_value&& pointerToSource)
{
	auto result = std::make_unique<execution::ObjectValue>(getAssigmentStatementDescriptor());
	result->setValue("_lExpression", std::move(lExpression));
	result->setValue("_rExpression", std::move(rExpression));
	result->setValue("_pointerToSource", std::move(pointerToSource));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::buildReferenceValue(gsl::not_null<dataStructures::Function*> f)
{
	return std::make_unique<execution::ReferenceValue>(f->object(), f->acutalObject()->type());
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

void cMCompiler::language::pushIf(runtime_value& conditionalInstruction, runtime_value&& newInstruction)
{
	auto object = castToObject(conditionalInstruction);
	assert(canCastReference(newInstruction->type(), getIInstruction()));
	auto collection = castToArray(object->getMemberValue("_ifBranch").get());
	collection->push(std::move(newInstruction));
}

void cMCompiler::language::pushElse(runtime_value& conditionalInstruction, runtime_value&& newInstruction)
{
	auto object = castToObject(conditionalInstruction);
	assert(canCastReference(newInstruction->type(), getIInstruction()));
	auto collection = castToArray(object->getMemberValue("_elseBranch").get());
	collection->push(std::move(newInstruction));
}