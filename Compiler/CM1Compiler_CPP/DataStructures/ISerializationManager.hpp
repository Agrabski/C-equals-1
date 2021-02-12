#pragma once
#include <memory>

namespace cMCompiler::dataStructures
{
	namespace execution
	{
		class IRuntimeValue;
	}
	using serialzation_id = size_t;
	constexpr serialzation_id null_id = 0L;
	class ISerializationManager
	{
	public:
		virtual serialzation_id serializeReference(std::unique_ptr<execution::IRuntimeValue> const& referenceValue) = 0;
	};
}