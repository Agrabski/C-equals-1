#pragma once


namespace cMCompiler::dataStructures
{
	template <typename T>
	class ObjectWithMetadata
	{
		T metadata_;
	public:
		T& metadata() noexcept { return metadata_; }
		T const& metadata() const noexcept { return metadata_; }
	};
}