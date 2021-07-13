#include "TypeInstantiationUtility.hpp"
#include "../DataStructures/execution/ObjectValue.hpp"
#include "CompileTimeInfrastrucutre/CompileTimeHeap.hpp"
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::instantiate(dataStructures::TypeReference t)
{
	//todo: finish
	return std::make_unique<dataStructures::execution::ObjectValue>(dataStructures::TypeReference{ t.type, 0 });
}

std::unique_ptr<cMCompiler::dataStructures::execution::ReferenceValue> cMCompiler::language::heapAllocate(dataStructures::TypeReference  type, bool unique)
{
	return compileTimeInfrastructure::CompileTimeHeap::instance().allocate(type, unique);
}

std::pair<
	std::unique_ptr<IRuntimeValue>,
	ObjectValue&
> cMCompiler::language::heapAllocateObject(gsl::not_null<dataStructures::Type*> type, bool unique)
{
	auto reference = heapAllocate({ type, 0 }, unique);
	not_null object = dynamic_cast<ObjectValue*>(reference->value()->get());
	return { std::move(reference), *object };
}

std::unique_ptr<cMCompiler::dataStructures::execution::ReferenceValue>
cMCompiler::language::moveToHeap(std::unique_ptr<dataStructures::execution::IRuntimeValue>&& value)
{
	auto result = heapAllocate(value->type());
	result->performAssigment(std::move(value));
	return result;
}
