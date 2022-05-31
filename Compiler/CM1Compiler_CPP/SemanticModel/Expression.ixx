module;
#include "../DataStructures/TypeReference.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../Execution/Utility.hpp"


export module SemanticModel:Expression;

import Execution.Marshalling;
import Execution.Prymitives;
import SourceFileReference;

namespace cMCompiler::semanticModel
{
	export struct Expression
	{
		execution::MarshalledPointer
			parentExpression = execution::MarshalledPointer(
				dataStructures::TypeReference{ language::getExpressionDescriptor(), 1 }, nullptr
			);

		execution::MarshalledPointer
			parentStatment = execution::MarshalledPointer(
				dataStructures::TypeReference{ language::getIInstruction(), 1 }, nullptr
			);
		execution::MarshalledNativeObject<SourcePointer> pointerToSource;
		Expression() = default;
	};
}

MAP_TO_TYPE_DESCRIPTOR(cMCompiler::semanticModel::Expression, cMCompiler::language::getExpressionDescriptor, 0);

