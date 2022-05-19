#include "pch.h"
#include "../Utilities/compilation_shim.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
import Execution.Allocation;
import Execution.Prymitives;

TEST(TestCaseName, TestName) {
	auto heap = cMCompiler::execution::CompileTimeHeap();
	cMCompiler::language::getDefaultPackage();
	auto usize = cMCompiler::language::getUsize();
	auto type = cMCompiler::dataStructures::TypeReference{ usize, 1 };
	auto object = heap.allocate(type);
	cMCompiler::execution::setPrymitiveValue<unsigned long long>(object, 32ULL);
	auto returned = cMCompiler::execution::getPrymitiveValue<unsigned long long>(object);
	ASSERT_EQ(returned, 32ULL);
	ASSERT_EQ(object->controlBlock.containedType.type , type.type);
	ASSERT_EQ(object->controlBlock.containedType.referenceCount , type.referenceCount);

}