export module Indicator:Value;

import std;

export namespace nen {
	class Value {
	public:
		constexpr Value() noexcept
			: val1(0), val2(0), val3(0) {}
		constexpr Value(const double v1, const double v2, const double v3) noexcept
			: val1(v1), val2(v2), val3(v3) {}

		constexpr ~Value() noexcept = default;

		constexpr decltype(auto) get1() const noexcept { return val1; }
		constexpr decltype(auto) get2() const noexcept { return val2; }
		constexpr decltype(auto) get3() const noexcept { return val3; }

	private:
		double val1;
		double val2;
		double val3;
	};

	class TwoVal {
	public:
		constexpr TwoVal() noexcept
			: val1(0), val2(0) {}
		constexpr TwoVal(const double v1, const double v2) noexcept
			: val1(v1), val2(v2) {}

		constexpr ~TwoVal() noexcept = default;

		constexpr decltype(auto) get1() const noexcept { return val1; }
		constexpr decltype(auto) get2() const noexcept { return val2; }

	private:
		double val1;
		double val2;
	};

	using val_t = std::vector<Value>;
	using twv_t = std::vector<TwoVal>;
}
