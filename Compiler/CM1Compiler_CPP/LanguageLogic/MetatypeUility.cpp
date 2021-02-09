#include "MetatypeUility.hpp"
#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "LiteralUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "../DataStructures/Namespace.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "../Utilities/pointer_cast.hpp"


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
	if (referenceToParent->type() == language::getFunctionDescriptor())
		return;
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

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildVariableDeclaration(gsl::not_null<dataStructures::Variable*> variable, runtime_value&& expression, gsl::not_null<dataStructures::Type*> type, runtime_value&& pointerToSource)
{
	std::terminate();
	return runtime_value();
}


std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::createVariableDescriptor(not_null<dataStructures::Variable*> variable)
{
	auto result = std::make_unique<dataStructures::execution::RuntimeVariableDescriptor>(getVariableDescriptor(), variable);
	return utilities::pointer_cast<IRuntimeValue>(std::move(result));
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::createTypeDescriptor(not_null<dataStructures::Type*> type)
{
	auto result = std::make_unique<dataStructures::execution::RuntimeTypeDescriptor>(getTypeDescriptor(), type);
	return utilities::pointer_cast<IRuntimeValue>(std::move(result));

}


std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildScopeTermination(runtime_value&& variables, runtime_value&& pointerToSource)
{
	auto result = instantiate(getScopeTerminationStatementDescriptor());
	not_null object = dynamic_cast<ObjectValue*>(result.get());
	object->setValue("_variables", std::move(variables));
	object->setValue("_pointerToSource", std::move(pointerToSource));
	return result;
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildIf(runtime_value&& expression, runtime_value&& pointerToSource)
{
	auto result = instantiate(getIfDescriptor());
	not_null object = dynamic_cast<ObjectValue*>(result.get());
	object->setValue("_expression", std::move(expression));
	object->setValue("_pointerToSource", std::move(pointerToSource));
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

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildFunctionCall(
	runtime_value&& referenceToCompiletimeFunction,
	runtime_value&& referenceToRuntimeFunction,
	runtime_value&& expressions,
	runtime_value&& pointerToSource)
{
	auto expression = instantiate(getFunctionCallExpressionDescriptor());
	not_null object = dynamic_cast<ObjectValue*>(expression.get());
	object->setValue("_compileTimeFunction", std::move(referenceToCompiletimeFunction));
	object->setValue("_runtimeTimeFunction", std::move(referenceToRuntimeFunction));
	object->setValue("_arguments", std::move(expressions));
	object->setValue("_pointerToSource", std::move(pointerToSource));

	auto result = instantiate(getFunctionCallStatementDescriptor());
	not_null resultObject = dynamic_cast<ObjectValue*>(result.get());
	resultObject->setValue("_function", std::move(expression));
	return result;
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<Type*> value)
{
	return std::make_unique<RuntimeTypeDescriptor>(getTypeDescriptor(), value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(gsl::not_null<Function*> value)
{
	return std::make_unique<RuntimeFunctionDescriptor>(getFunctionDescriptor(), value);
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

void cMCompiler::language::supplyScopeBegin(runtime_value& scopeBegin, dataStructures::Variable* variable)
{
	variable->provideScopeBegin(std::make_unique<execution::ReferenceValue>(&scopeBegin, scopeBegin->type()));
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