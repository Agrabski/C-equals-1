#include "printStackTrace.hpp"
#include <ranges>
#include "RuntimeException.hpp"
#include "Function.hpp"

void cMCompiler::dataStructures::printStackTrace(std::vector<stackFrame> const& stack, std::ostream& stream)
{
	for (auto const& frame : std::views::reverse(stack))
		stream
		<< "[ "
		<< frame.function->qualifiedName()
		<< " ]: "
		<< frame.currentInstruction.lineNumber_
		<< " ("
		<< frame.currentInstruction.filePath_
		<< ")"
		<< std::endl;
}
