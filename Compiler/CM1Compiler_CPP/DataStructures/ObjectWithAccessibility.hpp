#pragma once
#include "Accessibility.hpp"

namespace cMCompiler::dataStructures
{
	class ObjectWithAccessbility
	{
		Accessibility accessibility_;
	public:
		void setAccessibility(Accessibility acc) noexcept { accessibility_ = acc; }
		Accessibility accessibility() const noexcept { return accessibility_; }
	};
}