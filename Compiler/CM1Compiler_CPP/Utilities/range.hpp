#pragma once

namespace cMCompiler::utilities
{
	struct rangeIterator
	{
		size_t value;
		rangeIterator(size_t v) noexcept : value(v) {}
		rangeIterator& operator++() noexcept { ++value; return *this; }
		size_t operator*() const noexcept { return value; }
		bool operator!=(rangeIterator const& o) const noexcept { return value != o.value; }
	};

	struct range
	{
		size_t begin_;
		size_t end_;
		range(size_t begin, size_t end) noexcept : begin_(begin), end_(end) {}
		range(size_t end) noexcept : range(0, end) {}

		rangeIterator begin() const noexcept { return begin_; }
		rangeIterator end() const noexcept { return end_; }
	};
}