#pragma once
#include <gsl/gsl>
#include <optional>
#include "Generic.hpp"
#include "TypeReference.hpp"

namespace cMCompiler::dataStructures
{
	template<typename T>
	class Generic;

	template<typename T>
	struct GenericInstantiationData
	{
		gsl::not_null<Generic<T>*> basedOn;
		std::vector<TypeReference> parameters;
	};

	template<typename T>
	class InstantiationDataHolder
	{
		std::optional<GenericInstantiationData<T>> data_;
	public:
		GenericInstantiationData<T> * instantiationData() noexcept
		{
			if (data_)
				return &*data_;
			return nullptr;
		}

		void setInstantiationData(GenericInstantiationData<T>&& data) noexcept
		{
			data_ = std::move(data);
		}
		
		bool wasGenericInstantiated() const noexcept
		{
			return data_.has_value();
		}
	};
}
