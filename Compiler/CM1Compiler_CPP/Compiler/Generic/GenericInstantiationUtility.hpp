#pragma once
#include <filesystem>
#include "../../DataStructures/Generic.hpp"
#include "../../DataStructures/Function.hpp"
#include "../../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{

	template<typename T>
	struct GenericKey
	{
		not_null<dataStructures::Generic<T>*> prototype;
		std::vector<dataStructures::TypeReference> parameters;
		not_null<T*> value;
	};


	not_null<dataStructures::Function*> instantiate(
		dataStructures::Generic<dataStructures::Function>& function,
		std::vector<dataStructures::TypeReference> const& genericParameters,
		language::NameResolver&resolver,
		dataStructures::NameResolutionContext const&context,
		std::filesystem::path const& file
	);

	not_null<dataStructures::Type*> instantiate(
		dataStructures::Generic<dataStructures::Type>& type,
		std::vector<dataStructures::TypeReference> const& genericParameters,
		language::NameResolver& resolver,
		dataStructures::NameResolutionContext const& context,
		std::filesystem::path const& file
	);
}