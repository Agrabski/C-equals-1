#pragma once
#include <gsl.h>
#include "runtime_values.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"

namespace cMCompiler::language
{

	int getLineNumber(antlr4::tree::ParseTree* tree);
	bool isOfType(gsl::not_null<dataStructures::execution::IRuntimeValue*> value, gsl::not_null<dataStructures::Type*> type);

	void implementExpressionInterface(not_null<dataStructures::Type*> type);

	gsl::not_null<dataStructures::Type*> buildExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buidStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildIfDescriptor(gsl::not_null<dataStructures::Namespace*> irNs,
		gsl::not_null<dataStructures::Type*> baseStatement,
		gsl::not_null<dataStructures::Type*> expression);
	gsl::not_null<dataStructures::Type*> buildWhileDescriptor(gsl::not_null<dataStructures::Namespace*> irNs,
		gsl::not_null<dataStructures::Type*> baseStatement,
		gsl::not_null<dataStructures::Type*> expression);
	gsl::not_null<dataStructures::Type*> buildVariableDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildFieldDescriptor(gsl::not_null<dataStructures::Namespace*> compilerNs);
	gsl::not_null<dataStructures::Type*> buildVariableReferenceExpression(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildFieldAccessExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildBinaryOperatorExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildConstructorInvocationExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildAssigmentStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irns);

	gsl::not_null<dataStructures::Type*> buildLiteralExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildFunctionCallDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildFunctionCallStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildScopeTerminationStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildVariableDeclarationStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	void buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs);

	gsl::not_null<dataStructures::Type*> getVariableDescriptor();

	// expressions
	gsl::not_null<dataStructures::Type*> getExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getLiteralExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getVariableReferenceExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getFunctionCallExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getFieldAccessExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getBinaryOperatorExpressionDescriptor();
	gsl::not_null<dataStructures::Type*> getConstructorInvocationExpressionDescriptor();

	// statements
	gsl::not_null<dataStructures::Type*> getIInstruction();
	gsl::not_null<dataStructures::Type*> getIfDescriptor();
	gsl::not_null<dataStructures::Type*> getWhileDescriptor();
	gsl::not_null<dataStructures::Type*> getAssigmentStatementDescriptor();
	gsl::not_null<dataStructures::Type*> getScopeTerminationStatementDescriptor();
	gsl::not_null<dataStructures::Type*> getFunctionCallStatementDescriptor();
	gsl::not_null<dataStructures::Type*> getVariableDeclarationStatementDescriptor();

	language::runtime_value buildSourcePointer(std::string const& filename, antlr4::tree::ParseTree& tree);
}