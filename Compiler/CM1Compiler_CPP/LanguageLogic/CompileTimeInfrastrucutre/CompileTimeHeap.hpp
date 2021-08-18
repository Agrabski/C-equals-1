#pragma once
#include <vector>
#include <array>
#include <memory>
#include <gsl/gsl>
#include "../../DataStructures/execution/IRuntimeValue.h"
#include "../../DataStructures/execution/ReferenceValue.hpp"

using gsl::not_null;

namespace cMCompiler::language::compileTimeInfrastructure
{
	class CompileTimeHeap
	{
		using element_pointer = std::unique_ptr<dataStructures::execution::IRuntimeValue>;
		using block = std::array<element_pointer, 5>;
		using block_pointer = std::unique_ptr<block>;
		std::vector<block_pointer> memory_;
		element_pointer& getFreeElement();
		std::unique_ptr<dataStructures::execution::ReferenceValue> wrap(element_pointer&, dataStructures::TypeReference, bool unique = true);
	public:
		static CompileTimeHeap& instance();
		std::unique_ptr<dataStructures::execution::ReferenceValue> allocate(dataStructures::TypeReference  type, bool unique = true);
		void dealocate(dataStructures::execution::ReferenceValue&);
		std::vector<element_pointer const*> allocated() const
		{
			std::vector<element_pointer const*> result;
			for (auto const& block : memory_)
				for (auto const& e : *block)
					if (e != nullptr)
						result.push_back(&e);
			return result;
		}
	};
}