module;
#include "../Execution/Utility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp";

export module SourceFileReference;

import <string>;
import Execution.Prymitives;

namespace cMCompiler::semanticModel
{
	export struct SourcePointer
	{
		execution::MarshalledString filePath;
		execution::MarshalledInteger lineNumber;
	};

	export bool operator==(SourcePointer const& a, SourcePointer const& b)
	{
		return a.filePath.data == b.filePath.data && a.lineNumber.data == b.lineNumber.data;
	}
}
MAP_TO_TYPE_DESCRIPTOR(cMCompiler::semanticModel::SourcePointer, cMCompiler::language::getPointerToSource, 0);
