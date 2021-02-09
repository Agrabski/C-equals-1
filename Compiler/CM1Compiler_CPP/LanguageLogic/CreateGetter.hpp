#pragma once
#include "../DataStructures/Type.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Function*> createGetter(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type);

	void createIndexer(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type, gsl::not_null<dataStructures::Type*> returnType);
}