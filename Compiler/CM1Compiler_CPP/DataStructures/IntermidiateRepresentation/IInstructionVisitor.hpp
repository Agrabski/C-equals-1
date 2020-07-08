#pragma once
#include "FunctionCall.hpp"
#include "VariableDeclaration.hpp"
#include "IfElseStatement.hpp"
#include "ScopeTermination.hpp"
#include "AssigmentStatement.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IInstructionVisitor
	{
	public:
		virtual void visit(FunctionCall&) = 0;
		virtual void visit(VariableDeclaration&) = 0;
		virtual void visit(IfElseStatement&) = 0;
		virtual void visit(ScopeTermination&) = 0;
		virtual void visit(AssigmentStatement&) = 0;
	};
}