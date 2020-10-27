#pragma once
#include <filesystem>
#include "../../DataStructures/Generic/GenericFunction.hpp"
#include "../../DataStructures/Function.hpp"
#include "../../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	not_null<dataStructures::Function*> instantiate(
		dataStructures::generic::GenericFunction& function,
		std::vector<not_null<dataStructures::Type*>> const& genericParameters,
		language::NameResolver&resolver,
		language::NameResolutionContext&context,
		not_null<dataStructures::INamedObject*> parent,
		std::filesystem::path const& file
	);
}