#pragma once
#include <memory>
#include <map>
#include "../../DataStructures/ISerializationManager.hpp"

namespace cMCompiler::compiler::serialization
{
	class SerializationManager : public dataStructures::ISerializationManager
	{
		dataStructures::serialzation_id currentId_ = 1;
		std::map<void const*, dataStructures::serialzation_id> referenceIds_;
	public:
		dataStructures::serialzation_id serializeReference(std::unique_ptr<dataStructures::execution::IRuntimeValue> const& referenceValue) final
		{
			void const* key = referenceValue.get();
			if (!referenceIds_.contains(key))
				referenceIds_[key] = currentId_++;
			return referenceIds_[key];
		}

		dataStructures::serialzation_id getId(not_null<dataStructures::execution::IRuntimeValue const*> key) final
		{
			if (!referenceIds_.contains(key))
				referenceIds_[key] = currentId_++;
			return referenceIds_[key];
		}

		bool hasObjectOnHeap(std::unique_ptr<dataStructures::execution::IRuntimeValue> const& referenceValue)
		{

			return referenceIds_.contains(&referenceValue);
		}

	};
}