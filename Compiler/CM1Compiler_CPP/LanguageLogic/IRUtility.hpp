#pragma once
#include <gsl.h>
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buidStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	gsl::not_null<dataStructures::Type*> buildIfDescriptor(gsl::not_null<dataStructures::Namespace*> irNs, gsl::not_null<dataStructures::Type*> baseStatement);
	gsl::not_null<dataStructures::Type*> buildVariableDescriptor(gsl::not_null<dataStructures::Namespace*> irNs);
	void buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs);
}