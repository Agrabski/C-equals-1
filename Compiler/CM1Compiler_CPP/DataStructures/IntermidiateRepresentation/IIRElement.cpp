#include "IIRElement.hpp"
#include <gsl.h>

void cMCompiler::dataStructures::ir::IIRElement::suplyObject(std::unique_ptr<execution::IRuntimeValue>&& value)
{
	assert(value != nullptr && corespondingValue_ == nullptr);
	corespondingValue_ = std::move(value);
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue>& cMCompiler::dataStructures::ir::IIRElement::getObject()
{
	assert(corespondingValue_ != nullptr);
	return corespondingValue_;
}
