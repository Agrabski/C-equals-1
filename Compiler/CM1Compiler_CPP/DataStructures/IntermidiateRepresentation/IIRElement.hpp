#pragma once
#include <memory>
#include "../execution/IRuntimeValue.h"

namespace cMCompiler::dataStructures::ir
{
	class IIRElement
	{
		std::unique_ptr<execution::IRuntimeValue> corespondingValue_;
	protected:
	public:
		void suplyObject(std::unique_ptr<execution::IRuntimeValue>&& value);
		virtual void applyChanges() = 0;
		std::unique_ptr<execution::IRuntimeValue>& getObject();
	};
}
