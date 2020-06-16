#pragma once
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	gsl::not_null<dataStructures::PackageDatabase*> getDefaultPackage();
	gsl::not_null<dataStructures::Type*> getBool();
}
