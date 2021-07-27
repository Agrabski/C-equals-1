#include "ExpressionUtility.hpp"
#include <ranges>
#include "TypeInstantiationUtility.hpp"
#include "IRUtility.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "OverloadResolutionUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "InstantiateGeneric.hpp"

cMCompiler::language::runtime_value cMCompiler::language::buildAdressofExpression(runtime_value&& value, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getAdressofExpressionDescriptor());
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
	resultObject.setValue("_function", std::move(expression));
	resultObject.setValue("_pointerToSource", std::move(pointerToSource));
	return std::move(result);
}

cMCompiler::language::runtime_value cMCompiler::language::buildWhileLoop(runtime_value&& expression, runtime_value&& pointerToSource)
{
	auto [result, object] = heapAllocateObject(getWhileDescriptor());
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
		compile != nullptr ? getValueFor(compile) : nullptr,
		run != nullptr ? getValueFor(run) : nullptr,
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
		compile != nullptr ? getValueFor(compile) : nullptr,
		run != nullptr ? getValueFor(run) : nullptr,
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
