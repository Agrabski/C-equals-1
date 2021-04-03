#include "TypeReference.hpp"
#include "Type.hpp"

std::ostream& cMCompiler::dataStructures::operator<<(std::ostream& s, TypeReference const& ref)
{
	s << ref.type->qualifiedName();
	for (auto x = ref.referenceCount; x > 0; x--)
		s << '*';
	return s;
}

bool operator!=(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept
{
	return a.type != b.type || a.referenceCount != b.referenceCount;
}

bool operator==(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept
{
	return !(a != b);
}
