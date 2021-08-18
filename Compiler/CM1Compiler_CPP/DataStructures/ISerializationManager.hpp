#pragma once
#include <gsl/gsl>
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
		virtual dataStructures::serialzation_id getId(gsl::not_null<dataStructures::execution::IRuntimeValue const*> key) = 0;
	};
}