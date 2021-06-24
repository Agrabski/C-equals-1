#include "File.hpp"
#include <istream>
#include <fstream>

std::unique_ptr<std::istream> cMCompiler::fileSystem::File::open() const
{
	return std::make_unique<std::ifstream>(_path);
}

std::unique_ptr<std::istream> cMCompiler::fileSystem::StreamFile::open() const
{
	return std::make_unique<std::stringstream>(_stream.str());
}
