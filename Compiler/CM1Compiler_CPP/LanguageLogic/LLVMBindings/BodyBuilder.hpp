#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Type.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> getBodyBuilder() noexcept;
	gsl::not_null<dataStructures::Type*> buildBodyBuilder(
		gsl::not_null<dataStructures::Namespace*> backendns,
		gsl::not_null<dataStructures::Type*> llvmType,
		gsl::not_null<dataStructures::Type*> llvmValue,
		gsl::not_null<dataStructures::Type*> llvmFunction);

}