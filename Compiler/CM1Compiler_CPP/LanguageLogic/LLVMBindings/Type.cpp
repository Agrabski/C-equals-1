#include "Type.hpp"

using namespace cMCompiler::dataStructures;

gsl::not_null<Type*> cMCompiler::language::buildTypeDescriptor(gsl::not_null<dataStructures::Namespace*> backendns)
{
	auto result = backendns->append<Type>("llvmType");

	//todo: do
	return result;
}