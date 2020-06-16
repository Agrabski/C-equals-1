#pragma once
#include <string>
#include <vector>
#include <ostream>

namespace cMCompiler::dataStructures
{
	class QualifiedName
	{
		std::vector<std::string> name_;
	public:
		size_t size() const noexcept { return name_.size(); }
		QualifiedName(std::string path);
		QualifiedName parent() const;
		QualifiedName next() const;
		std::string const& peek() const noexcept { return name_.front(); }
		QualifiedName operator+(const std::string& s)
		{
			auto result = *this;
			result.name_.push_back(s);
			return result;
		}
		QualifiedName() noexcept = default;
		
		friend std::ostream& operator<<(std::ostream& os, QualifiedName const& name);
		friend QualifiedName operator+(const std::string& s, const QualifiedName& qn);
	};

	QualifiedName operator+(const std::string& s, const QualifiedName& qn);

	std::ostream& operator<<(std::ostream& os, QualifiedName const& name);
}
