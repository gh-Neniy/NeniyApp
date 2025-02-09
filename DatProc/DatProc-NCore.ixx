export module DatProc:NCore;

import std;

export namespace nen {
	template<typename C> class NCore {
	public:
		constexpr NCore() noexcept
			: cached(), iterBegin(), iterEnd(), _size() {}
		template<typename newC> constexpr NCore(newC&& newCached) noexcept
			: cached(std::forward<newC>(newCached)), iterBegin(cached.cbegin()), iterEnd(cached.cend()), _size(cached.size()) {}

		NCore(const NCore&)				= delete;
		NCore(NCore&&)					= delete;
		NCore& operator=(const NCore&)	= delete;
		NCore& operator=(NCore&&)		= delete;

		constexpr ~NCore() noexcept = default;

		template<typename newC> constexpr void set(newC&& newCached) noexcept
		{ cached = std::forward<newC>(newCached); iterBegin = cached.cbegin(); iterEnd = cached.cend(); _size = cached.size(); }

		constexpr decltype(auto) begin()	const noexcept { return iterBegin;	}
		constexpr decltype(auto) end()		const noexcept { return iterEnd;	}
		constexpr decltype(auto) size()		const noexcept { return _size;		}

	private:
		C cached;
		C::const_iterator iterBegin;
		C::const_iterator iterEnd;
		size_t _size;
	};
}
