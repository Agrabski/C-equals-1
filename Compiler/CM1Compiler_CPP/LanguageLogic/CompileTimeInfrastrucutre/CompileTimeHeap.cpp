#include "CompileTimeHeap.hpp"
#include "../TypeInstantiationUtility.hpp"

using namespace cMCompiler::language::compileTimeInfrastructure;
using namespace cMCompiler::dataStructures::execution;

CompileTimeHeap::element_pointer& cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::getFreeElement()
{
	for (auto const& block : memory_)
	{
		auto element = std::find(block->begin(), block->end(), nullptr);
		if (element != block->end())
			return *element;
	}
	memory_.push_back(std::make_unique<block>());
	return memory_.back()->front();
}

std::unique_ptr<ReferenceValue> cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::wrap(element_pointer& element, dataStructures::TypeReference type, bool unique)
{
	type.referenceCount += 1;
	if(unique)
		return std::make_unique<ReferenceValue>(&element, type, [this](auto e) {dealocate(e); });
	return ReferenceValue::make(&element, type);
}

cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap& 
	cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::instance()
{
	static CompileTimeHeap heap;
	return heap;
}

std::unique_ptr<ReferenceValue> cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::allocate(dataStructures::TypeReference type, bool unique)
{
	auto& element = getFreeElement();
	element = instantiate(type);
	return wrap(element, type, unique);
}

void cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::dealocate(dataStructures::execution::ReferenceValue& val)
{
	for (auto const& block : memory_)
	{
		auto element = std::find_if(block->begin(), block->end(), [&](const auto& e) {return e.get() == val.value()->get(); });
		if (element != block->end())
		{
			*element = nullptr;
		}
	}
	std::terminate();

}
