#pragma once
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	gsl::not_null<dataStructures::PackageDatabase*> getDefaultPackage();
	gsl::not_null<dataStructures::Type*> getBool();
	gsl::not_null<dataStructures::Type*> getUsize();
	gsl::not_null<dataStructures::Type*> getString();
	gsl::not_null<dataStructures::Type*> getTypeDescriptor();
	gsl::not_null<dataStructures::Type*> getFunctionDescriptor();
	gsl::not_null<dataStructures::Type*> getNamespaceDescriptor();
	gsl::not_null<dataStructures::Type*> getFieldDescriptor();
	gsl::not_null<dataStructures::Type*> getPointerToSource();
	gsl::not_null<dataStructures::Attribute*> getCompileTimeAttribute();
	gsl::not_null<dataStructures::Type*> getCollectionTypeFor(gsl::not_null<dataStructures::Type*>elementType);



}
