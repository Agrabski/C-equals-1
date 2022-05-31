module;
#include "../DataStructures/TypeReference.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../Execution/Utility.hpp"


export module SemanticModel:VariableReferenceExpression;

import Execution.Marshalling;
import Execution.Prymitives;
import SourceFileReference;
import :Expression;

namespace cMCompiler::semanticModel
{
	export struct VariableReferenceExpression : Expression
	{
		execution::MarshalledNativeObject<dataStructures::Variable*> variable;
		VariableReferenceExpression(dataStructures::Variable* v) noexcept : variable(v) {}
		VariableReferenceExpression() noexcept = default;
	};
}

MAP_TO_TYPE_DESCRIPTOR(cMCompiler::semanticModel::VariableReferenceExpression, cMCompiler::language::getVariableReferenceExpressionDescriptor, 0);

