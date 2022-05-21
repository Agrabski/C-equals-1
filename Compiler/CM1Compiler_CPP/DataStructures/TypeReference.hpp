#pragma once
#include <ostream>

namespace cMCompiler::dataStructures
{
	class Type;
	struct TypeReference
	{
		Type* type = nullptr;
		size_t referenceCount = 0;
		std::string typeName() const;
		bool isVoidType() const noexcept { return type == nullptr; }
		TypeReference reference() const noexcept;
		TypeReference dereference() const noexcept;
		TypeReference baseType() const noexcept;
		TypeReference() = default;
		TypeReference(Type* t) noexcept : type(t) {}
		TypeReference(Type* t, size_t refCount) noexcept : type(t), referenceCount(refCount) {}
		bool isPointer() const noexcept;
		bool isIntegral() const noexcept;

		bool isCompilerIntrinsic() const noexcept;
	};
	std::ostream& operator<< (std::ostream& s, TypeReference const& ref);


}
bool operator!=(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept;
bool operator==(cMCompiler::dataStructures::TypeReference const& a, cMCompiler::dataStructures::TypeReference const& b) noexcept;
