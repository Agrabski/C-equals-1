#pragma once
namespace cMCompiler::dataStructures
{
	template<typename Flags, Flags noneValue>
	struct MetadataObject
	{
	public:
		Flags flags_;
		void appendFlag(Flags flag) noexcept
		{
			flags_ = flags_ | flag;
		}

		bool hasFlag(Flags flag) const noexcept
		{
			return (flags_ & flag) == noneValue;
		}
	};
}