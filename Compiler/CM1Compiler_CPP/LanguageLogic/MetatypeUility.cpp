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
#include "GetterExecution.hpp"
#include "ExpressionUtility.hpp"
#include "OverloadResolutionUtility.hpp"
#include "TypeCoercionUtility.hpp"
#include "../DataStructures/execution/RuntimePackageDescriptor.hpp"

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

cMCompiler::dataStructures::TypeReference cMCompiler::language::getExpressionType(std::unique_ptr<dataStructures::execution::IRuntimeValue>& expression)
{
	return executeGetter<TypeReference>(expression, "type"s);

}

void cMCompiler::language::suplyParent(runtime_value& instruction, runtime_value&& referenceToParent)
{
	if (isOfType(referenceToParent.get(), language::getFunctionDescriptor()))
		return;
	auto object = dereferenceAs<ObjectValue>(instruction.get());
	assert(coerce(referenceToParent->type(), object->getMemberType("_parent")));
	object->setValue("_parent", std::move(referenceToParent));
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildVariableDeclaration(gsl::not_null<dataStructures::Variable*> variable, runtime_value&& expression, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getVariableDeclarationStatementDescriptor());
	object.setValue("_variable", getValueFor(variable));
	object.setValue("_expression", std::move(expression));
	object.setValue("_sourcePointer", std::move(pointerToSource));
	return std::move(result);
}


std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::createVariableDescriptor(not_null<dataStructures::Variable*> variable)
{
	auto result = std::make_unique<dataStructures::execution::RuntimeVariableDescriptor>(TypeReference{ getVariableDescriptor(), 0 }, variable);
	return utilities::pointer_cast<IRuntimeValue>(std::move(result));
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::createTypeDescriptor(dataStructures::TypeReference  type)
{
	auto result = std::make_unique<dataStructures::execution::RuntimeTypeDescriptor>(TypeReference{ getTypeDescriptor(), 0}, type);
	return utilities::pointer_cast<IRuntimeValue>(std::move(result));

}


std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildScopeTermination(runtime_value&& variables, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getScopeTerminationStatementDescriptor());
	object.setValue("_variables", std::move(variables));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildIf(runtime_value&& expression, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getIfDescriptor());
	object.setValue("_expression", std::move(expression));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	object.setValue("_ifBranch", convertCollection({}, {getIInstruction(),1}));
	object.setValue("_elseBranch", convertCollection({}, { getIInstruction(),1 }));
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildAssigmentStatement(runtime_value&& lExpression, runtime_value&& rExpression, runtime_value&& pointerToSource)
{
	auto [result, object] = language::heapAllocateObject(getAssigmentStatementDescriptor());
	// todo: parent statement
	//setParent(lExpression.get(), result->copy());
	//setParent(rExpression.get(), result->copy());
	object.setValue("_lExpression", std::move(lExpression));
	object.setValue("_rExpression", std::move(rExpression));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildReturnStatement(runtime_value&& Expression, runtime_value&& pointerToSource)
{
	auto result = buildReturnStatement(std::move(pointerToSource));
	auto object = dereferenceAs<ObjectValue>(result.get());
	object->setValue("_expression", std::move(Expression));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::language::buildReturnStatement(runtime_value&& pointerToSource)
{
	auto [result, object] = language::heapAllocateObject(getReturnStatementDescriptor());
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildFunctionCallExpression(runtime_value&& referenceToCompiletimeFunction, runtime_value&& referenceToRuntimeFunction, runtime_value&& expressions, runtime_value&& pointerToSource)
{
	auto [expression, object] = heapAllocateObject(getFunctionCallExpressionDescriptor());
	assert(referenceToCompiletimeFunction != nullptr || referenceToRuntimeFunction != nullptr);
	for (auto& arg : *dereferenceAs<dataStructures::execution::ArrayValue>(expressions.get()))
		setParent(arg.get(), expression->copy());
	object.setValue("_compiletimeFunction", std::move(referenceToCompiletimeFunction));
	object.setValue("_runtimeFunction", std::move(referenceToRuntimeFunction));
	object.setValue("_arguments", std::move(expressions));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(expression);
}

cMCompiler::language::runtime_value cMCompiler::language::buildIndexOperatorExpression(
	runtime_value&& expression,
	dataStructures::TypeReference type,
	std::vector<runtime_value>&& argumentExpressions,
	runtime_value&& pointerToSource)
{
	return buildMethodCallExpression(
		std::move(expression),
		type,
		std::move(argumentExpressions),
		"operator_[]",
		std::move(pointerToSource));
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildConstructorInvocationExpression(runtime_value&& referenceToCompiletimeFunction, runtime_value&& referenceToRuntimeFunction, runtime_value&& expressions, runtime_value&& pointerToSource)
{

	auto [expression, object] = heapAllocateObject(getConstructorInvocationExpressionDescriptor());
	for (auto& arg : *dereferenceAs<dataStructures::execution::ArrayValue>(expressions.get()))
		setParent(arg.get(), expression->copy());
	object.setValue("_compiletimeConstructor", std::move(referenceToCompiletimeFunction));
	object.setValue("_runtimeConstructor", std::move(referenceToRuntimeFunction));
	object.setValue("_arguments", std::move(expressions));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(expression);
}

cMCompiler::language::runtime_value cMCompiler::language::buildBinaryOperatorExpression(
	runtime_value&& referenceToCompiletimeFunction,
	runtime_value&& referenceToRuntimeFunction,
	runtime_value&& arg1,
	runtime_value&& arg2,
	runtime_value&& pointerToSource
)
{
	auto [expression, object] = heapAllocateObject(getBinaryOperatorExpressionDescriptor());
	setParent(arg1.get(), expression->copy());
	setParent(arg2.get(), expression->copy());
	object.setValue("_compiletimeFunction", std::move(referenceToCompiletimeFunction));
	object.setValue("_runtimeFunction", std::move(referenceToRuntimeFunction));
	object.setValue("_arg1", std::move(arg1));
	object.setValue("_arg2", std::move(arg2));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(expression);
}

cMCompiler::language::runtime_value cMCompiler::language::buildBinaryOperatorExpression(
	NameResolver& nr,
	NameResolutionContext& context,
	std::string operatorKind,
	runtime_value&& arg1,
	runtime_value&& arg2,
	runtime_value&& pointerToSource)
{
	auto candidates = nr.resolveOperatorOverloadSet(
		operatorKind,
		language::getExpressionType(arg1),
		language::getExpressionType(arg2),
		context);
	std::vector<language::runtime_value> args;
	args.push_back(std::move(arg1));
	args.push_back(std::move(arg2));
	auto compileTime = resolveOverload(candidates, args, true, false);
	auto runTime = resolveOverload(candidates, args, false, true);
	if (!(compileTime != nullptr || runTime != nullptr))
		std::cout << "";
	assert(compileTime != nullptr || runTime != nullptr);
	return language::buildBinaryOperatorExpression(
		language::getValueFor(compileTime),
		language::getValueFor(runTime),
		std::move(args[0]),
		std::move(args[1]),
		std::move(pointerToSource)
	);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(TypeReference value)
{
	return std::make_unique<RuntimeTypeDescriptor>(TypeReference{ getTypeDescriptor(), 0 }, value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(Variable* value)
{
	return std::make_unique<RuntimeVariableDescriptor>(TypeReference{ getVariableDescriptor(),0 }, value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(dataStructures::Type* t)
{
		return getValueFor({ t, 0 });
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(Function* value)
{
	return std::make_unique<RuntimeFunctionDescriptor>(TypeReference{ getFunctionDescriptor(), 0 }, value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(Field* value)
{
	return std::make_unique<RuntimeFieldDescriptor>(TypeReference{ getFieldDescriptor(), 0 }, value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::getValueFor(PackageDatabase* value)
{
	return std::make_unique<RuntimePackageDescriptor>(TypeReference{ getPackageDescriptor(), 0 }, value);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::buildPointerToSource(std::string const& filename, unsigned long long lineNumber)
{

	auto result = instantiate({ getPointerToSource(), 0 });
	auto& object = dynamic_cast<ObjectValue&>(*result);
	object.setValue("filename", buildStringValue(filename));
	object.setValue("lineNumber", buildIntegerValue(getUsize(), reinterpret_cast<number_component*>(&lineNumber), sizeof(lineNumber)));
	return result;
}

void cMCompiler::language::supplyScopeBegin(runtime_value& scopeBegin, dataStructures::Variable* variable)
{
	variable->provideScopeBegin(execution::ReferenceValue::make(&scopeBegin, scopeBegin->type()));
}

void cMCompiler::language::pushIf(runtime_value& conditionalInstruction, runtime_value&& newInstruction)
{
	auto object = dereferenceAs<ObjectValue>(conditionalInstruction.get());
	assert(coerce(newInstruction->type(), { getIInstruction(), 1 }));
	auto collection = castToArray(object->getMemberValue("_ifBranch").get());
	collection->push(std::move(newInstruction));
}

void cMCompiler::language::pushElse(runtime_value& conditionalInstruction, runtime_value&& newInstruction)
{
	auto object = dereferenceAs<ObjectValue>(conditionalInstruction.get());
	assert(coerce(newInstruction->type(), { getIInstruction(), 1 }));
	auto collection = castToArray(object->getMemberValue("_elseBranch").get());
	collection->push(std::move(newInstruction));
}

void cMCompiler::language::pushWhile(runtime_value& whileInstruction, runtime_value&& newInstruction)
{
	auto object = dereferenceAs<ObjectValue>(whileInstruction.get());
	assert(coerce(newInstruction->type(), { getIInstruction(), 1 }));
	auto collection = dereferenceAs<ArrayValue>(object->getMemberValue("_body").get());
	collection->push(std::move(newInstruction));
}
