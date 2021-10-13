#include "Libraries.hpp"
#include "FilesystemLibrary.hpp"

void cMCompiler::language::libraries::createLibraries(gsl::not_null<dataStructures::Namespace*> ns)
{
	createFilesystemLibrary(ns);
}