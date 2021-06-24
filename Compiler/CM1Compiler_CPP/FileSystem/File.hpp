#pragma once
#include <filesystem>
#include <istream>

namespace cMCompiler::fileSystem
{
	template<typename T>
	concept file = requires(T const& a)
	{
		{ a.open() } -> std::same_as<std::unique_ptr<std::istream>>;
		{ a.path() } -> std::same_as<std::filesystem::path const&>;
	};


	class File
	{
		std::filesystem::path _path;
	public:
		explicit File(std::filesystem::path const& path) : _path{ path } {}
		std::unique_ptr<std::istream> open() const;
		constexpr std::filesystem::path const& path() const noexcept { return _path; }
	};

	class StreamFile
	{
		std::stringstream _stream;
		std::filesystem::path const _path;
	public:
		explicit StreamFile(std::stringstream && stream, std::filesystem::path const& p) : _stream{ std::move(stream)}, _path(p) {}
		std::unique_ptr<std::istream> open() const;
		constexpr std::filesystem::path const& path() const noexcept { return _path; }
	};
}
