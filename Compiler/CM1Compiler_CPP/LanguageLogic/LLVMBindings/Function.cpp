#include "Function.hpp"
#include "../BuiltInPackageBuildUtility.hpp"
using namespace cMCompiler::dataStructures;

gsl::not_null<Type*> cMCompiler::language::buildFunctionDescriptor(gsl::not_null<dataStructures::Namespace*> backendns, gsl::not_null<dataStructures::Type*> llvmType)
{
	auto result = backendns->append<Type>("llvmFunction");

	//todo: do
	return result;
}

gsl::not_null<Type*> cMCompiler::language::getLLVMFunctionDescriptor()
{
	return getDefaultPackage()->rootNamespace()
		->get<Namespace>("compiler")
		->get<Namespace>("backend")
		->get<Type>("llvmFunction");
}