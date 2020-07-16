#pragma once
#include <string>
#include <map>
#include <gsl.h>
#include "execution/IRuntimeValue.h"

namespace cMCompiler::dataStructures
{
	class Attribute;
	class AttributeInstance
	{
		std::unique_ptr<execution::IRuntimeValue> instanceObject_;
		Attribute* basedOn_;
	public:
		AttributeInstance(gsl::not_null<Attribute*> base, std::unique_ptr<execution::IRuntimeValue>&& instanceObject) :
			basedOn_(base), instanceObject_(std::move(instanceObject)) {}
		std::unique_ptr<execution::IRuntimeValue>& objectInstance() noexcept { return instanceObject_; }

		Attribute* basedOn() noexcept { return basedOn_; }
	};
}
