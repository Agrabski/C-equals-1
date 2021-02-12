#pragma once
#include <memory>
#include <map>
#include "../../DataStructures/ISerializationManager.hpp"

namespace cMCompiler::compiler::serialization
{
	class SerializationManager : dataStructures::ISerializationManager
	{
		dataStructures::serialzation_id currentId_ = 1;
		std::map<void*, dataStructures::serialzation_id> referenceIds_;
	public:
		dataStructures::serialzation_id serializeReference(std::unique_ptr<dataStructures::execution::IRuntimeValue> const& referenceValue) final
		{
			auto const key = &referenceValue;
			if (!referenceIds_.contains(key))
				referenceIds_[key] = currentId_++;
			return referenceIds_[key];
		}
	};
}