#pragma once
#include <memory>
#include <gsl.h>
#include "runtime_values.hpp"
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ArrayValue.hpp"
#include "../DataStructures/execution/InstructionCode.hpp"


namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::ObjectValue> buildObjectFor(gsl::not_null<dataStructures::Type*> type);
	std::unique_ptr<dataStructures::execution::ObjectValue> buildObjectFor(gsl::not_null<dataStructures::Namespace*> ns);


	runtime_value buildVariableDeclaration(gsl::not_null<dataStructures::Variable*> variable, runtime_value&& expression, gsl::not_null<dataStructures::Type*> type, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildScopeTermination(runtime_value&& variables, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildIf(runtime_value&& expression, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildAssigmentStatement(runtime_value&& lExpression, runtime_value&& rExpression, runtime_value&& pointerToSource);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildFunctionCall(
		runtime_value&& referenceToCompiletimeFunction,
		runtime_value&& referenceToRuntimeFunction,
		runtime_value&& expressions,
		runtime_value&& pointerToSource);

	std::unique_ptr<dataStructures::execution::IRuntimeValue> createVariableDescriptor(not_null<dataStructures::Variable*> variable);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> createTypeDescriptor(not_null<dataStructures::Type*> type);


	void suplyParent(runtime_value& instruction, runtime_value&& referenceToParent);
	



	template<typename T>
	runtime_value buildReferenceValue(gsl::not_null<T*> f)
	{
		using cMCompiler::dataStructures::execution::ReferenceValue;
		return std::make_unique<ReferenceValue>(f->object(), f->acutalObject()->type());
	}

	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Type*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Function*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Field*>);

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
}