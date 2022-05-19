#include "../DataStructures/Type.hpp"

bool m(cMCompiler::dataStructures::TypeReference& t)
{
	t.isPointer() || t.isCompilerIntrinsic() || t.isIntegral();
}
