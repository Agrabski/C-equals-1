#pragma once
#include <string>
#include <vector>

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
	};
}
