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
	dataStructures::TypeReference getExpressionType(std::unique_ptr<dataStructures::execution::IRuntimeValue>& expression);

	runtime_value buildVariableDeclaration(gsl::not_null<dataStructures::Variable*> variable, runtime_value&& expression, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildScopeTermination(runtime_value&& variables, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildIf(runtime_value&& expression, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildAssigmentStatement(runtime_value&& lExpression, runtime_value&& rExpression, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildFunctionCallStatement(
		runtime_value&& expression,
		runtime_value&& pointerToSource);

	runtime_value buildWhileLoop(
		runtime_value&& expression,
		runtime_value&& pointerToSource
	);

	std::unique_ptr<dataStructures::execution::IRuntimeValue> createVariableDescriptor(not_null<dataStructures::Variable*> variable);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> createTypeDescriptor(dataStructures::TypeReference  type);


	void suplyParent(runtime_value& instruction, runtime_value&& referenceToParent);





	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(dataStructures::TypeReference);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(not_null<dataStructures::Type*> t);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Function*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Field*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Variable*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::PackageDatabase*>);

	template<typename T>
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(std::vector<gsl::not_null<T*>>const& c)
	{
		auto result = std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
		for (auto const e : c)
			result.push_back(getValueFor(e));

		// todo: fix nullptr type
		return convertToCollection(std::move(result), dataStructures::TypeReference{ getPackageDescriptor(), 0 });
	}

	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildPointerToSource(
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