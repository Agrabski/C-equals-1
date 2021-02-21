#pragma once

namespace cMCompiler::dataStructures
{
	class IValueHolder
	{
		unsigned const char referenceLevel_;
	public:
		unsigned const char referenceLevel() const noexcept { return referenceLevel_; }
		IValueHolder(unsigned const char referenceLevel) noexcept : referenceLevel_(referenceLevel) {}
	};
}