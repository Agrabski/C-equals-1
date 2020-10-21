#pragma once
#include <string>
#include "GenericObject.hpp"
#include "../INamedObject.hpp"

namespace cMCompiler::dataStructures::generic
{
	class GenericFunction : 
		public GenericObject,
		public INamedObject
	{
		std::string body_;
	public:
		std::string& body() { return body_; }
	};
}