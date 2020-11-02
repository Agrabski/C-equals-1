#pragma once
#include <memory>
#include <gsl.h>
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/IntermidiateRepresentation/MemberAccessExpression.hpp"
#include "../DataStructures/IntermidiateRepresentation/VariableDeclaration.hpp"
#include "../DataStructures/IntermidiateRepresentation/IfElseStatement.hpp"
#include "../DataStructures/IntermidiateRepresentation/FunctionCall.hpp"
#include "../DataStructures/IntermidiateRepresentation/AssigmentStatement.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::ObjectValue> buildObjectFor(gsl::not_null<dataStructures::Type*> type);
	std::unique_ptr<dataStructures::execution::ObjectValue> buildObjectFor(gsl::not_null<dataStructures::Namespace*> ns);

	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildObjectFor(gsl::not_null<dataStructures::ir::ScopeTermination*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildObjectFor(gsl::not_null<dataStructures::ir::VariableDeclaration*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildObjectFor(gsl::not_null<dataStructures::ir::IfElseStatement*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildObjectFor(gsl::not_null<dataStructures::ir::FunctionCall*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildObjectFor(gsl::not_null<dataStructures::ir::AssigmentStatement*>);


	void supplyValueTo(gsl::not_null<dataStructures::ir::ScopeTermination*> st);
	void supplyValueTo(gsl::not_null<dataStructures::ir::VariableDeclaration*>);
	void supplyValueTo(gsl::not_null<dataStructures::ir::IfElseStatement*>);
	void supplyValueTo(gsl::not_null<dataStructures::ir::FunctionCall*>);
	void supplyValueTo(gsl::not_null<dataStructures::ir::AssigmentStatement*>);

	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Type*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Function*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Field*>);

	std::unique_ptr<dataStructures::execution::IRuntimeValue> buildPointerToSource(
		std::string const& filename,
		unsigned long long lineNumber
	);


}