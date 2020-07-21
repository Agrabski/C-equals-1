#include "MarkCompileTimeOnly.hpp"
#include "../../DataStructures/execution/RuntimeFunctionDescriptor.hpp"

using namespace cMCompiler;
using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue>
cMCompiler::language::compileTimeFunctions::markCompileTimeOnly
(
	std::map<std::string, std::unique_ptr<IRuntimeValue>>&& valueMap,
	std::map<std::string, not_null<dataStructures::Type*>> genericParameters
)
{
	assert(genericParameters.size() == 0);
	assert(valueMap.size() == 1);
	auto function = dynamic_cast<RuntimeFunctionDescriptor*>(valueMap["function"].get());
	function->value()->metadata().flags_ =
		function->value()->metadata().flags_ | dataStructures::FunctionFlags::ExcludeAtCompileTime;
}
