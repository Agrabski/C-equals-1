#include "CompilerInterface.hpp"

cMCompiler::language::CompilerInterface& cMCompiler::language::CompilerInterface::getInstance()
{
	return *instance_;
}
