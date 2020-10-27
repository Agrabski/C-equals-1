#pragma once
#include <string>
#include <memory>
#include "INamedObject.hpp"
#include "Type.hpp"
#include "Function.hpp"
#include "Accessibility.hpp"
#include "Attribute.hpp"
#include "Enum.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
	class Function;
	class Attribute;
	class Enum;
	class Namespace : public INamedObject
	{
		std::vector<std::unique_ptr<Type>> types_;
		std::vector<std::unique_ptr<Function>> functions_;
		std::vector<std::unique_ptr<Namespace>> namespaces_;
		std::vector<std::unique_ptr<Attribute>> attributes_;
		std::vector<std::unique_ptr<Enum>> enums_;
#pragma region Bulshit
		template<typename T, typename std::enable_if<std::is_same<typename T, typename Type>::value, int>::type = 0>
		std::vector<std::unique_ptr<T>>& getAppropriate() noexcept
		{
			return types_;
		}
		template<typename T, typename std::enable_if<std::is_same<typename T, typename Function>::value, int>::type = 0>
		std::vector<std::unique_ptr<T>>& getAppropriate() noexcept
		{
			return functions_;
		}
		template<typename T, typename std::enable_if<std::is_same<typename T, typename Namespace>::value, int>::type = 0>
		std::vector<std::unique_ptr<T>>& getAppropriate()noexcept
		{
			return namespaces_;
		}
		template<typename T, typename std::enable_if<std::is_same<typename T, typename Attribute>::value, int>::type = 0>
		std::vector<std::unique_ptr<T>>& getAppropriate()noexcept
		{
			return attributes_;
		}

		template<typename T, typename std::enable_if<std::is_same<typename T, typename Enum>::value, int>::type = 0>
		std::vector<std::unique_ptr<T>>& getAppropriate()noexcept
		{
			return enums_;
		}
#pragma endregion

	public:
		std::vector<Namespace*> namespaces();
		Namespace(std::string name, Namespace* parent)
			: INamedObject(name, parent) {}
		std::vector<INamedObject*> children() final;
		template<typename T>
		gsl::not_null<T*> append(std::string name)
		{
			auto tmp = std::make_unique<T>(name, this);
			auto const result = tmp.get();
			getAppropriate<T>().push_back(std::move(tmp));
			return result;
		}

		template<typename T>
		std::vector<T*> get()
		{
			std::vector<T*> result;
			auto& collection = getAppropriate<T>();
			for (auto& e : collection)
				result.push_back(e.get());
			return result;
		}

		template<typename T>
		T* get(std::string name)
		{
			auto& collection = getAppropriate<T>();
			auto result = std::find_if(begin(collection), end(collection), [&](auto const& e) {return e->name() == name; });
			if (result != end(collection))
				return result->get();
			return nullptr;

		}


		// Inherited via INamedObject
		virtual std::vector<validation::ValidationError> validateContent() const override;

	};
}
