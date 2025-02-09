export module Analysis:Result;

export namespace nen {
	class Result {
	public:
		constexpr Result() noexcept
			: grow(0), fall(0) {}
		constexpr Result(const int up, const int down) noexcept
			: grow(up), fall(down) {}

		constexpr ~Result() noexcept = default;

		constexpr void growth(const int val)	noexcept { grow += val; }
		constexpr void drop(const int val)		noexcept { fall += val; }

		constexpr decltype(auto) get() const noexcept { return grow - fall; }

		constexpr decltype(auto) operator+(const Result& rhs) noexcept { return Result(this->grow + rhs.grow, this->fall + rhs.fall); }

		constexpr void operator+=(const Result& rhs) noexcept { this->grow += rhs.grow; this->fall += rhs.fall; }

	private:
		int grow;
		int fall;
	};
}
