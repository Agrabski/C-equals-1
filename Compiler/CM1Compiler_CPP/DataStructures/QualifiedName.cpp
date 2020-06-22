#include "QualifiedName.hpp"
#include <algorithm>
#include <sstream>

using namespace cMCompiler::dataStructures;

QualifiedName::QualifiedName(std::string path)
{
	std::replace(path.begin(), path.end(), ':', ' ');
	std::string tmp;
	std::stringstream sstream(path);
	while (!sstream.eof())
	{
		sstream >> tmp;
		name_.push_back(tmp);
	}
}

QualifiedName cMCompiler::dataStructures::QualifiedName::parent() const
{
	auto result = *this;
	result.name_.pop_back();
	return result;
}

QualifiedName cMCompiler::dataStructures::QualifiedName::next() const
{
	auto result = *this;
	result.name_.erase(result.name_.begin());
	return result;
}

cMCompiler::dataStructures::QualifiedName::operator std::string() const
{
	std::stringstream result;
	result << *this;
	return result.str();
}

QualifiedName cMCompiler::dataStructures::operator+(const std::string& s, const QualifiedName& qn)
{
	QualifiedName result = qn;
	result.name_.insert(result.name_.begin(), s);
	return result;
}
std::ostream& cMCompiler::dataStructures::operator<<(std::ostream& os, QualifiedName const& name)
{
	for (auto& n : name.name_)
		os << "::" << n;
	return os;
}