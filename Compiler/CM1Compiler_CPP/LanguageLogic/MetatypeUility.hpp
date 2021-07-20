#pragma once
#include <memory>
#include <gsl.h>
#include <vector>
#include "runtime_values.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ArrayValue.hpp"
#include "../DataStructures/execution/InstructionCode.hpp"


namespace cMCompiler::language
{
	dataStructures::TypeReference getExpressionType(runtime_value& expression);

	runtime_value buildVariableDeclaration(gsl::not_null<dataStructures::Variable*> variable, runtime_value&& expression, runtime_value&& pointerToSource);
	runtime_value buildScopeTermination(runtime_value&& variables, runtime_value&& pointerToSource);
	runtime_value buildIf(runtime_value&& expression, runtime_value&& pointerToSource);
	runtime_value buildAssigmentStatement(runtime_value&& lExpression, runtime_value&& rExpression, runtime_value&& pointerToSource);
	runtime_value buildReturnStatement(runtime_value&& Expression, runtime_value&& pointerToSource);
	runtime_value buildReturnStatement(runtime_value&& pointerToSource);
	runtime_value buildFunctionCallStatement(
		runtime_value&& expression,
		runtime_value&& pointerToSource);

	runtime_value buildWhileLoop(
		runtime_value&& expression,
		runtime_value&& pointerToSource
	);

	runtime_value createVariableDescriptor(not_null<dataStructures::Variable*> variable);
	runtime_value createTypeDescriptor(dataStructures::TypeReference  type);


	void suplyParent(runtime_value& instruction, runtime_value&& referenceToParent);



	dataStructures::Type* getType(dataStructures::PackageDatabase*);
	dataStructures::Type* getType(dataStructures::TypeReference*);
	dataStructures::Type* getType(dataStructures::Variable*);

	runtime_value getValueFor(dataStructures::TypeReference);
	runtime_value getValueFor(dataStructures::Type* t);
	runtime_value getValueFor(dataStructures::Generic<dataStructures::Type>* t);
	runtime_value getValueFor(dataStructures::Function*);
	runtime_value getValueFor(dataStructures::Field*);
	runtime_value getValueFor(dataStructures::Variable*);
	runtime_value getValueFor(dataStructures::PackageDatabase*);
	runtime_value getValueFor(dataStructures::GenericInstantiationData<dataStructures::Type>*);

	template<typename T>
	runtime_value convertCollection(std::vector<not_null<T*>>const& collection, dataStructures::TypeReference elementType)
	{
		auto result = std::make_unique<dataStructures::execution::ArrayValue>(dataStructures::TypeReference{ getCollectionTypeFor(elementType),0 }, elementType);
		for (auto e : collection)
			result->push(getValueFor(e.get()));
		return result;
	}

	template<typename T>
	runtime_value getValueFor(std::vector<std::unique_ptr<T>>const& c)
	{
		auto result = std::vector<runtime_value>();
		for (auto const& e : c)
			result.push_back(getValueFor(e.get()));

		// todo: fix nullptr type
		return convertToCollection(std::move(result), dataStructures::TypeReference{ getType((T*)nullptr), 0 });
	}

	template<typename T>
	runtime_value getValueFor(std::vector<T>const& c)
	{
		auto result = std::vector<runtime_value>();
		for (auto const& e : c)
			result.push_back(getValueFor(e));

		// todo: fix nullptr type
		return convertToCollection(std::move(result), dataStructures::TypeReference{ getType((T*)nullptr), 0 });
	}

	template<typename T>
	runtime_value getValueFor(std::vector<not_null<T*>>const& c)
	{
		auto result = std::vector<runtime_value>();
		for (auto const& e : c)
			result.push_back(getValueFor(e));

		// todo: fix nullptr type
		return convertToCollection(std::move(result), dataStructures::TypeReference{ getType((T*)nullptr), 0 });
	}

	runtime_value buildPointerToSource(
		std::string const& filename,
		unsigned long long lineNumber
	);


	dataStructures::execution::InstructionCode getInstructionCode(runtime_value& value);
	runtime_value buildInstructionCode(dataStructures::execution::InstructionCode);



	void supplyScopeBegin(runtime_value& scopeBegin, dataStructures::Variable* variable);
	void supplyScopeEnd(runtime_value& scopeEnd, dataStructures::Variable* variable);


	void pushIf(runtime_value& conditionalInstruction, runtime_value&& newInstruction);
	void pushElse(runtime_value& conditionalInstruction, runtime_value&& newInstruction);
	void pushWhile(runtime_value& whileInstruction, runtime_value&& newInstruction);
}