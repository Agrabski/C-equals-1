#include "pch.h"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../DataStructures/TypeReference.hpp"
import Execution.Allocation;
import SemanticModel;
import Execution.Prymitives;

using namespace cMCompiler::semanticModel;
using namespace cMCompiler::execution;
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;

TEST(TestCaseName, VariableReferenceExpressionMarshallsCorrectly) {
	auto package = PackageDatabase("test");
	package.appendDependency(getDefaultPackage());
	auto variable = package.rootNamespace()->append<Function>("test_function")->appendLocalVariable("test", { getUsize(), 0 });

	auto heap = cMCompiler::execution::CompileTimeHeap();

	auto variableRef = cMCompiler::semanticModel::VariableReferenceExpression{ MarshalledNativeObject{variable.get()}};
	auto marshalledObject = heap.allocateNative<VariableReferenceExpression>(VariableReferenceExpression(variableRef));

	ASSERT_EQ(marshalledObject->controlBlock.containedType.type, getVariableReferenceExpressionDescriptor());
	ASSERT_EQ(marshalledObject->controlBlock.containedType.referenceCount, 0);
	ASSERT_EQ(marshalledObject->data.variable.data, variableRef.variable.data);
}
