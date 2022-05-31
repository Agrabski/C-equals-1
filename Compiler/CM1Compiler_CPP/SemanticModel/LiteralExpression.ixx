module;
#include "../DataStructures/TypeReference.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../Execution/Utility.hpp"


export module SemanticModel:LiteralExpression;

import Execution.Marshalling;
import Execution.Prymitives;
import SourceFileReference;
import :Expression;

namespace cMCompiler::semanticModel
{
	export struct LiteralExpression : Expression
	{
		execution::MarshalledPointer value;
	};
}

MAP_TO_TYPE_DESCRIPTOR(cMCompiler::semanticModel::LiteralExpression, cMCompiler::language::getLiteralExpressionDescriptor, 0);

