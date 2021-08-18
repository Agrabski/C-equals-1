#pragma once
#include <gsl/gsl>
#include <filesystem>
#include "CreateGetter.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "runtime_values.hpp"
#include "../DataStructures/Type.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/execution/WrapperTypeTranslation.hpp"
#include "../Utilities/collections.hpp"

namespace cMCompiler::language
{
	dataStructures::Function* convert(dataStructures::Function* r)
	{
		return r;
	}

	dataStructures::Type* convert(dataStructures::TypeReference * r)
	{
		return r->type;
	}

	template<dataStructures::execution::wrapped_type T>
	void appendMetadataBindings(not_null<dataStructures::Type*> descriptorType)
	{
		using namespace std::string_literals;
		using namespace dataStructures;
		using namespace dataStructures::execution;
		descriptorType->appendGeneric<Function>(
			std::vector<std::string>{ "T" },
			[descriptorType](auto const& args) -> not_null<Function*>
			{
				auto retType = args[0];
				auto result = createNativeObjectGetter<T>(
					getGenericMangledName("get_attribute", args),
					descriptorType,
					retType.reference(),
					[retType](T* s) -> runtime_value
					{
						auto self = convert(s);
						using namespace std::views;
						auto attributes = self->attributes()
							| filter(getIsDescribedByTypePredicate(retType));
						if (auto result = utilities::first(attributes); result)
							return ReferenceValue::make(&(*result)->objectInstance(), retType);
						return ReferenceValue::make(nullptr, retType);

					}
				);
				return result;
			},
			"get_attribute"s,
				NameResolutionContext(getDefaultPackage()),
				std::filesystem::path("C-=-1_library_internals.cm")
				);
	}
}
