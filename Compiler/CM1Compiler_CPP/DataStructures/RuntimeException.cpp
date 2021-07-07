#include "RuntimeException.hpp"

void cMCompiler::dataStructures::RuntimeException::push(stackFrame&& frame)
{
	stackTrace_.emplace_back(std::move(frame));
}

std::vector<cMCompiler::dataStructures::stackFrame> const& cMCompiler::dataStructures::RuntimeException::trace() const noexcept
{
	return stackTrace_;
}
