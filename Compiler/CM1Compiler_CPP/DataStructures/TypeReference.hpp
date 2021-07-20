#pragma once
#include <ostream>

namespace cMCompiler::dataStructures
{
	class Type;
	struct TypeReference
	{
		Type* type;
		size_t referenceCount;
		std::string typeName() const;
		TypeReference getReference() const noexcept;
		TypeReference dereference() const noexcept;
		TypeReference baseType() const noexcept;
	};
	std::ostream& operator<< (std::ostream& s, TypeReference const& ref);


}
	bool operator!=(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept;
	bool operator==(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept;