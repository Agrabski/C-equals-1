export module SemanticModel;
import Execution.Marshalling;
import SourceFileReference;

export import :VariableReferenceExpression;
export import :Expression;
export import :LiteralExpression;


namespace cMCompiler::semanticModel
{
	export void setupExpression(
		Expression& expression,
		execution::MarshalledObject* parentExpression,
		SourcePointer&& sourcePointer)
	{
		expression.parentExpression.data = parentExpression;
		expression.pointerToSource.data = sourcePointer;
	}

	export void setupRootExpression(
		Expression& expression,
		execution::MarshalledObject* parentStatement,
		SourcePointer&& sourcePointer)
	{
		expression.parentStatment.data = parentStatement;
		expression.pointerToSource.data = sourcePointer;
	}
}
