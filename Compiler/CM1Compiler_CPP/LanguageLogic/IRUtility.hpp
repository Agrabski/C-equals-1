#pragma once
#include <gsl.h>
#include "runtime_values.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	bool isOfType(gsl::not_null<dataStructures::execution::IRuntimeValue*> value, gsl::not_null<dataStructures::Type*> type);

	gsl::not_null<dataStructures::Type*> buidStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildIfDescriptor(gsl::not_null<dataStructures::Namespace*> irNs, gsl::not_null<dataStructures::Type*> baseStatement);
	gsl::not_null<dataStructures::Type*> buildVariableDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildLiteralExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildFunctionCallDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	void buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs);

	gsl::not_null<dataStructures::Type*> getVariableDescriptor();

	// expressions
	gsl::not_null<dataStructures::Type*> getExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getLiteralExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getVariableReferenceExpressionDescriptor();

	// statements
	gsl::not_null<dataStructures::Type*> getIInstruction();
	gsl::not_null<dataStructures::Type*> getIfDescriptor();
	gsl::not_null<dataStructures::Type*> getAssigmentStatementDescriptor();
	gsl::not_null<dataStructures::Type*> getFunctionCallDescriptor();
	gsl::not_null<dataStructures::Type*> getScopeTerminationStatementDescriptor();
}