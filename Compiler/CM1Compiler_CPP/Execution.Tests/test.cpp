#include "pch.h"
#include "../Utilities/compilation_shim.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
import Execution.Allocation;
import Execution.Prymitives;

using namespace cMCompiler::language;
using namespace cMCompiler::execution;
using namespace cMCompiler::dataStructures;

TEST(TestCaseName, AllocatePrymitiveWithBasicApi)
{
	auto heap = cMCompiler::execution::CompileTimeHeap();
	getDefaultPackage();
	auto usize = cMCompiler::language::getUsize();
	auto type = cMCompiler::dataStructures::TypeReference{ usize, 0 };
	auto object = heap.allocate(type);
	cMCompiler::execution::setPrymitiveValue<unsigned long long>(object, 32ULL);
	auto returned = cMCompiler::execution::getPrymitiveValue<unsigned long long>(object);
	ASSERT_EQ(returned, 32ULL);
	ASSERT_EQ(object->controlBlock.containedType.type , type.type);
	ASSERT_EQ(object->controlBlock.containedType.referenceCount , type.referenceCount);

}


TEST(TestCaseName, AllocatePrymitiveWithGenericApi)
{
	auto heap = cMCompiler::execution::CompileTimeHeap();
	getDefaultPackage();
	auto usize = cMCompiler::language::getUsize();
	auto type = cMCompiler::dataStructures::TypeReference{ usize, 0 };

	auto object = heap.allocateNative(32ULL);
	ASSERT_EQ(object->data, 32ULL);
	ASSERT_EQ(object->controlBlock.containedType.type, type.type);
	ASSERT_EQ(object->controlBlock.containedType.referenceCount, type.referenceCount);

}


TEST(TestCaseName, GetFieldFromComposite)
{
	auto package = cMCompiler::dataStructures::PackageDatabase("test");
	package.appendDependency(getDefaultPackage());
	auto composite = package.rootNamespace()->append<Type>("test_type");
	auto f1 = composite->appendField("f1", { getUsize(), 0 });
	auto f2 = composite->appendField("f2", { getUsize(), 0 });

	auto heap = cMCompiler::execution::CompileTimeHeap();
	auto object = heap.allocate({ composite, 0 });

	not_null marshalledF1 = tryGetFieldAddress(object, f1);
	not_null marshalledF2 = tryGetFieldAddress(object, f2);

	setPrymitiveValue(marshalledF1, 1ULL);
	setPrymitiveValue(marshalledF2, 15ULL);

	ASSERT_EQ(marshalledF1->controlBlock.containedType.type, f1->type().type);
	ASSERT_EQ(marshalledF1->controlBlock.containedType.referenceCount, 0);
	ASSERT_EQ(getPrymitiveValue<unsigned long long>(marshalledF1), 1ULL);

	ASSERT_EQ(marshalledF2->controlBlock.containedType.type, f2->type().type);
	ASSERT_EQ(marshalledF2->controlBlock.containedType.referenceCount, 0);
	ASSERT_EQ(getPrymitiveValue<unsigned long long>(marshalledF2), 15ULL);

}

