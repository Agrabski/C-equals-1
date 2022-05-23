module;
#include "../DataStructures/TypeReference.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../Execution/Utility.hpp"


export module SemanticModel:VariableReferenceExpression;

import Execution.Marshalling;
import Execution.Prymitives;

namespace cMCompiler::semanticModel
{
	export struct VariableReferenceExpression
	{
		execution::MarshalledNativeObject<dataStructures::Variable*> variable;
		execution::MarshalledPointer
			parent = execution::MarshalledPointer(
				dataStructures::TypeReference{ language::getExpressionDescriptor(), 1 }, nullptr
				);
		execution::MarshalledNativeObject<dataStructures::SourcePointer> pointerToSource;
		//todo: add pointer to source
	};
}

MAP_TO_TYPE_DESCRIPTOR(cMCompiler::semanticModel::VariableReferenceExpression, cMCompiler::language::getVariableReferenceExpressionDescriptor, 0);

