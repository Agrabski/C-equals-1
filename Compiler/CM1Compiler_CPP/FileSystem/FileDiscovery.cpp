#include "FileDiscovery.hpp"

using namespace cMCompiler::fileSystem;
std::vector<File> cMCompiler::fileSystem::loadFiles(std::filesystem::path const& path, std::string const& extension)
{
	auto result = std::vector<File>();
	auto x = std::filesystem::absolute(path);
	for (auto& f : std::filesystem::recursive_directory_iterator(path))
		if (!f.is_directory() && f.path().has_extension() && f.path().extension() == ".cm")
			result.emplace_back(f);
	return result;

}