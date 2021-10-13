#pragma once
#include <gsl/gsl>
#include <iostream>
#include "../../DataStructures/Namespace.hpp"
#include "../../DataStructures/Type.hpp"
#include "../runtime_values.hpp"

namespace cMCompiler::language::libraries
{
	gsl::not_null<dataStructures::Type*> getFileDescriptor();

	void createFilesystemLibrary(gsl::not_null<dataStructures::Namespace*> ns);
}

namespace cMCompiler::language
{
	runtime_value getValueFor(std::unique_ptr<std::iostream>&&);

}
