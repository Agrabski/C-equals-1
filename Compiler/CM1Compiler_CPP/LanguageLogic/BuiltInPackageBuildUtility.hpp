#pragma once
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"


namespace cMCompiler::language
{
	gsl::not_null<dataStructures::PackageDatabase*> buildDefaultPackage();
}
