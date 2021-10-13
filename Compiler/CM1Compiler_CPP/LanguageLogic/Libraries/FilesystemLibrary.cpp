#include "FilesystemLibrary.hpp"
#include "../BuiltInPackageBuildUtility.hpp"

using gsl::not_null;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::language::libraries;

cMCompiler::dataStructures::Type* fileDescriptor;

not_null<Type*> createFileDescriptor(not_null<Namespace*> ns)
{
	auto result = ns->append<Type>("fileDescriptor");
	fileDescriptor = result.get();

	return result;
}

void createFileWriteFunctions(not_null<Type*> fd, not_null<Namespace*> ns, not_null<Type*> string)
{

}

void cMCompiler::language::libraries::createFilesystemLibrary(not_null<Namespace*> ns)
{
	auto rootNs = ns->append<Namespace>("filesystem");

	auto fd = createFileDescriptor(rootNs);
	createFileWriteFunctions(fd, rootNs, getString());
}
