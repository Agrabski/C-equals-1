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

std::unique_ptr<ReferenceValue> cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::wrap(element_pointer& element, dataStructures::Type* type)
{
	return std::make_unique<ReferenceValue>(&element, type);
}

std::unique_ptr<ReferenceValue> cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::allocate(dataStructures::Type* type)
{
	auto& element = getFreeElement();
	element = instantiate(type);
	return wrap(element, type);
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
