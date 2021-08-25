#pragma once
#include <gsl/gsl>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/Type.hpp"


namespace cMCompiler::language
{
	gsl::not_null<dataStructures::PackageDatabase*> getDefaultPackage();
	gsl::not_null<dataStructures::Type*> getBool();
	gsl::not_null<dataStructures::Generic<dataStructures::Type>*> getArray();
	gsl::not_null<dataStructures::Type*> getUsize();
	gsl::not_null<dataStructures::Type*> getString();
	gsl::not_null<dataStructures::Type*> getChar();
	gsl::not_null<dataStructures::Type*> getByte();
	gsl::not_null<dataStructures::Type*> getTypeDescriptor();
	gsl::not_null<dataStructures::Type*> getFunctionDescriptor();
	gsl::not_null<dataStructures::Type*> getNamespaceDescriptor();
	gsl::not_null<dataStructures::Type*> getPackageDescriptor();
	gsl::not_null<dataStructures::Type*> getFieldDescriptor();
	gsl::not_null<dataStructures::Type*> getPointerToSource();
	gsl::not_null<dataStructures::Type*> getTypeGenericInstantiationInfo();
	gsl::not_null<dataStructures::Type*> getFunctionGenericInstantiationInfo();
	gsl::not_null<dataStructures::Type*> getGenericTypeDescriptor();
	gsl::not_null<dataStructures::Type*> getGenericFunctionDescriptor();
	gsl::not_null<dataStructures::Attribute*> getCompileTimeAttribute();
	gsl::not_null<dataStructures::Attribute*> getCompilerEntryPointAttribute();
	gsl::not_null<dataStructures::Type*> getCollectionTypeFor(cMCompiler::dataStructures::TypeReference elementType);
	gsl::not_null<dataStructures::Function*> getNullFor(cMCompiler::dataStructures::TypeReference elementType);
	gsl::not_null<dataStructures::Generic<dataStructures::Function>*> getNull();
	gsl::not_null<dataStructures::Function*> getHeapAllocateFor(cMCompiler::dataStructures::TypeReference objectType);



}
