#include "CompileTimeAllocate.hpp"
#include "../CompileTimeInfrastrucutre/CompileTimeHeap.hpp"

using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::language::compileTimeFunctions;

std::unique_ptr<IRuntimeValue>
cMCompiler::language::compileTimeFunctions::compileTimeAllocate
(
	std::map<std::string, std::unique_ptr<IRuntimeValue>>&& valueMap,
	std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters
)
{
	assert(valueMap.empty());
	assert(genericParameters.size() == 1);
	return compileTimeInfrastructure::CompileTimeHeap::instance().allocate(genericParameters.begin()->second);
}