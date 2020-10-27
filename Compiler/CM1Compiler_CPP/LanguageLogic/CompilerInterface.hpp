#pragma once
#include <exception>
#include <string>
#include "../DataStructures/SourcePointer.hpp"

namespace cMCompiler::language
{
	class CompilerInterface
	{
		static inline CompilerInterface* instance_ = nullptr;
	protected:
		CompilerInterface()
		{
			if (instance_ != nullptr)
				std::terminate();
			instance_ = this;
		}
	public:
		static CompilerInterface& getInstance();
		virtual void raiseError(std::string const& text, dataStructures::SourcePointer const& source, unsigned long long const code) = 0;
	};
}
