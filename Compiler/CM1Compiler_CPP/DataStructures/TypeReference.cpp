#include "TypeReference.hpp"
#include "Type.hpp"

std::ostream& cMCompiler::dataStructures::operator<<(std::ostream& s, TypeReference const& ref)
{
	if (ref.type == nullptr)
		return s;
	s << ref.type->name();
	for (auto x = ref.referenceCount; x > 0; x--)
		s << '*';
	return s;
}

bool operator!=(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept
{
	if (a.type == nullptr || b.type == nullptr)
		return a.referenceCount != b.referenceCount;
	return a.type != b.type || a.referenceCount != b.referenceCount;
}

bool operator==(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept
{
	return !(a != b);
}

std::string cMCompiler::dataStructures::TypeReference::typeName() const
{
	return type->name();
}
