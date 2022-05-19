#include "TypeReference.hpp"
#include "Type.hpp"

std::ostream& cMCompiler::dataStructures::operator<<(std::ostream& s, TypeReference const& ref)
{
	if (ref.type == nullptr)
		return s;
	s << ref.typeName();
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
	if (type == nullptr)
		return "void";
	return type->name();
}

cMCompiler::dataStructures::TypeReference cMCompiler::dataStructures::TypeReference::reference() const noexcept
{
	return { type, referenceCount + 1 };
}

cMCompiler::dataStructures::TypeReference cMCompiler::dataStructures::TypeReference::dereference() const noexcept
{
	assert(referenceCount - 1 >= 0);
	return { type,referenceCount - 1 };
}

cMCompiler::dataStructures::TypeReference cMCompiler::dataStructures::TypeReference::baseType() const noexcept
{
	return { type, 0 };
}

bool cMCompiler::dataStructures::TypeReference::isPointer() const noexcept
{
	return referenceCount > 0;
}

bool cMCompiler::dataStructures::TypeReference::isIntegral() const noexcept
{
	return !isPointer() && !isVoidType() && type->metadata().hasFlag(TypeFlags::IsIntegralType);
}

bool cMCompiler::dataStructures::TypeReference::isCompilerIntrinsic() const noexcept
{
	return !isPointer() && !isVoidType() && type->metadata().hasFlag(TypeFlags::IsCompilerIntrinsic);
}
