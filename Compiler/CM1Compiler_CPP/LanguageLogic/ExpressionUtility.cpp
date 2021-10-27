#include "ExpressionUtility.hpp"
#include <ranges>
#include "TypeInstantiationUtility.hpp"
#include "IRUtility.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "OverloadResolutionUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "InstantiateGeneric.hpp"

using namespace cMCompiler::dataStructures::execution;

cMCompiler::language::runtime_value cMCompiler::language::buildAdressofExpression(runtime_value&& value, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getAdressofExpressionDescriptor());
	setParent(value.get(), result->copy());
	object.setValue("_expression", std::move(value));
	object.setValue("_pointerToSource", std::move(pointerToSource));

	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildValueLiteralExpression(runtime_value&& value, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getLiteralExpressionDescriptor());
	object.setValue("_value", std::move(value));
	object.setValue("_pointerToSource", std::move(pointerToSource));

	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildArrayLiteralExpression(runtime_value&& expressions, dataStructures::TypeReference valueType, runtime_value&& pointerToSource)
{
	assert(valueType.type != nullptr);
	assert(dereferenceAs<dataStructures::execution::ObjectValue>(pointerToSource.get()) != nullptr);
	auto [result, object] = heapAllocateObject(getArrayLiteralExpression());
	object.setValue("_value", std::move(expressions));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	object.setValue("_type", getValueFor({ getCollectionTypeFor(valueType), 0 }));
	object.setValue("_elementType", getValueFor(valueType));

	return std::move(result);
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::buildFunctionCallStatement(
	runtime_value&& expression,
	runtime_value&& pointerToSource)
{
	assert(dereferenceAs<dataStructures::execution::ObjectValue>(pointerToSource.get()) != nullptr);
	auto [result, resultObject] = heapAllocateObject(getFunctionCallStatementDescriptor());
	//todo: parent
	//dereferenceAs<dataStructures::execution::ObjectValue>(expression.get())->setValue("_parentExpression", result->copy());
	setParentStatement(expression.get(), result->copy());
	resultObject.setValue("_function", std::move(expression));
	resultObject.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildWhileLoop(runtime_value&& expression, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getWhileDescriptor());
	setParentStatement(expression.get(), result->copy());
	object.setValue("_expression", std::move(expression));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	object.setValue("_body", std::make_unique<dataStructures::execution::ArrayValue>(dataStructures::TypeReference{ getCollectionTypeFor({ getIInstruction(), 1 }),0 }, dataStructures::TypeReference{ getIInstruction(), 1 }));
	return std::move(result);
}


cMCompiler::language::runtime_value cMCompiler::language::buildMethodCallExpression(
	runtime_value&& expression,
	dataStructures::TypeReference type,
	std::vector<runtime_value>&& argumentExpressions,
	std::string const& methodName,
	std::vector<dataStructures::TypeReference> const& genericParameters,
	runtime_value&& pointerToSource,
	NameResolver nr,
	NameResolutionContext context,
	std::filesystem::path p)
{
	assert(dereferenceAs<dataStructures::execution::ObjectValue>(pointerToSource.get()) != nullptr);


	auto methods = std::vector<not_null<dataStructures::Function*>>();
	if (genericParameters.size() == 0)
		return buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(argumentExpressions),
			methodName,
			std::move(pointerToSource)
		);
	else
	{
		auto self = runtime_value();
		if (getExpressionType(expression).referenceCount < 1)
			self = buildAdressofExpression(std::move(expression), pointerToSource->copy());
		else
			self = std::move(expression);
		argumentExpressions.insert(argumentExpressions.begin(), std::move(self));

		std::vector<not_null<dataStructures::execution::IRuntimeValue*>> expressions;
		for (auto const& e : argumentExpressions)
			expressions.push_back(e.get());
		auto generics = type.type->genericMethods();
		auto g = generics | std::views::filter([&](auto g)
			{
				return g->name() == methodName;
			});
		for (auto gener : g)
			methods.push_back(compiler::instantiate(
				*gener,
				genericParameters,
				nr,
				context,
				p
			));

	}
	auto compile = resolveOverload(methods, argumentExpressions, true, false);
	auto run = resolveOverload(methods, argumentExpressions, false, true);

	if (compile == nullptr && run == nullptr)
		std::cerr << "Method " << methodName << " does not exist on type " << type.type->qualifiedName() << std::endl;
	assert(compile != nullptr || run != nullptr);

	std::vector<not_null<dataStructures::execution::IRuntimeValue*>> expressions;
	for (auto const& e : argumentExpressions)
		expressions.push_back(e.get());

	auto result = buildFunctionCallExpression(
		getValueFor(compile),
		getValueFor(run),
		language::convertToCollection(std::move(argumentExpressions), { getExpressionDescriptor(), 1 }),
		std::move(pointerToSource));
	assert(dynamic_cast<dataStructures::execution::ReferenceValue*>(result.get()) != nullptr);

	for (auto arg : expressions)
		setParent(arg, result->copy());
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildMethodCallExpression(
	runtime_value&& expression,
	dataStructures::TypeReference type,
	std::vector<runtime_value>&& argumentExpressions,
	std::string const& methodName,
	runtime_value&& pointerToSource
)
{
	assert(dereferenceAs<dataStructures::execution::ObjectValue>(pointerToSource.get()) != nullptr);
	auto self = runtime_value();
	if (getExpressionType(expression).referenceCount < 1)
		self = buildAdressofExpression(std::move(expression), pointerToSource->copy());
	else
		self = std::move(expression);
	argumentExpressions.insert(argumentExpressions.begin(), std::move(self));
	std::vector<not_null<dataStructures::execution::IRuntimeValue*>> expressions;
	for (auto const& e : argumentExpressions)
		expressions.push_back(e.get());

	auto methods = std::vector<not_null<dataStructures::Function*>>();
	methods = type.type->methods();
	auto remove = std::ranges::remove_if(methods, [&](auto const e) {return e->name() != methodName; });
	if (remove.begin() != remove.end())
		methods.erase(remove.begin(), remove.end());
	auto compile = resolveOverload(methods, argumentExpressions, true, false);
	auto run = resolveOverload(methods, argumentExpressions, false, true);

	if (compile == nullptr && run == nullptr)
		std::cerr << "Method " << methodName << " does not exist on type " << type.type->qualifiedName() << std::endl;
	assert(compile != nullptr || run != nullptr);

	auto result = buildFunctionCallExpression(
		getValueFor(compile),
		getValueFor(run),
		language::convertToCollection(std::move(argumentExpressions), { getExpressionDescriptor(), 1 }),
		std::move(pointerToSource));
	assert(dynamic_cast<dataStructures::execution::ReferenceValue*>(result.get()) != nullptr);
	for (auto arg : expressions)
		setParent(arg, result->copy());
	return std::move(result);
}


cMCompiler::language::runtime_value cMCompiler::language::buildFieldAccessExpression(runtime_value&& expression, gsl::not_null<dataStructures::Field*> field, runtime_value&& pointerToSource)
{
	assert(dereferenceAs<dataStructures::execution::ObjectValue>(pointerToSource.get()) != nullptr);
	auto [result, object] = heapAllocateObject(getFieldAccessExpressionDescriptor());
	setParent(expression.get(), result->copy());
	object.setValue("_field", getValueFor(field));
	object.setValue("_expression", std::move(expression));
	object.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildVariableReferenceExpressionDescriptor(gsl::not_null<dataStructures::Variable*> var)
{
	auto [result, object] = heapAllocateObject(getVariableReferenceExpressionDescriptor());
	object.setValue("_variable", createVariableDescriptor(var));
	object.setValue("_type", createTypeDescriptor(var->type()));
	return std::move(result);
}

void cMCompiler::language::setParent(not_null<dataStructures::execution::IRuntimeValue*> expression, runtime_value&& parentReference)
{
	if (parentReference != nullptr)
	{
		not_null complex = dereferenceAs<dataStructures::execution::IComplexRuntimeValue>(expression.get());
		complex->setValue("_parentExpression", std::move(parentReference));
	}
}

void cMCompiler::language::setParentStatement(not_null<dataStructures::execution::IRuntimeValue*> expression, runtime_value&& parentReference)
{
	if (parentReference != nullptr)
	{
		not_null complex = dereferenceAs<dataStructures::execution::IComplexRuntimeValue>(expression.get());
		complex->setValue("_parentStatment", std::move(parentReference));
	}
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
	object.setValue("_parentStatment", ReferenceValue::make(nullptr, object.getMemberType("_parentStatment").dereference()));
	return std::move(expression);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::buildDereferenceExpression(runtime_value&& expression, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getDereferenceExpression());

	object.setValue("_pointerToSource", std::move(pointerToSource));
	setParent(expression.get(), result->copy());
	object.setValue("_expression", std::move(expression));

	return std::move(result);
}

std::unique_ptr<IRuntimeValue> cMCompiler::language::buildNewExpression(
	runtime_value&& referenceToruntimeNew,
	runtime_value&& referenceTocompiletimeNew,
	runtime_value&& referenceToRuntimeConstructor,
	runtime_value&& referenceToCompiletimeContructor,
	runtime_value&& expressions,
	runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getNewExpressionDescriptor());

	object.setValue("_runtimeNewOperator", std::move(referenceToruntimeNew));
	object.setValue("_compiletimeNewOperator", std::move(referenceTocompiletimeNew));
	object.setValue("_compiletimeConstructor", std::move(referenceToCompiletimeContructor));
	object.setValue("_runtimeConstructor", std::move(referenceToRuntimeConstructor));
	object.setValue("_arguments", std::move(expressions));
	object.setValue("_sourcePointer", std::move(pointerToSource));

	return std::move(result);
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
