#pragma once
#include <memory>
#include <gsl.h>
#include "../DataStructures/Field.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"

namespace cMCompiler::language
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Type*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Function*>);
	std::unique_ptr<dataStructures::execution::IRuntimeValue> getValueFor(gsl::not_null<dataStructures::Field*>);
}