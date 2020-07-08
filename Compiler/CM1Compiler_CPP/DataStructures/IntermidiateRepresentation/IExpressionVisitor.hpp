#pragma once
#include "IExpression.hpp"
#include "ValueLiteralExpression.hpp"
#include "VariableReferenceExpression.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IExpressionVisitor
	{
	public:
		virtual void visit(ValueLiteralExpression& expression) = 0;
		virtual void visit(VariableReferenceExpression& expression) = 0;
	};
}