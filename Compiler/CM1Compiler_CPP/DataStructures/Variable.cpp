#include "Variable.hpp"

using namespace cMCompiler::dataStructures;

not_null<Type*> cMCompiler::dataStructures::Variable::type() noexcept
{
	return type_;
}
