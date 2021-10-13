#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Namespace.hpp"
#include "../../DataStructures/Type.hpp"


namespace cMCompiler::language::libraries
{
	gsl::not_null<dataStructures::Type*> getFileDescriptor();
	void createFilesystemLibrary(gsl::not_null<dataStructures::Namespace*> ns);
}
