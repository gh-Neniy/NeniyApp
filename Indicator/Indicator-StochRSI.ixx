export module Indicator:StochRSI;

import :HighAndLow;
import DatProc;
import :Value;

class CalcMA {
public:
	constexpr CalcMA(const double val) noexcept
		: val1(val), val2(0), val3(0), sum(val) {}
	constexpr ~CalcMA() noexcept = default;

	constexpr void init2(const double val) noexcept { sum += val2 = val; }
	constexpr void init3(const double val) noexcept { sum += val3 = val; }

	constexpr void insert(const double val) noexcept
	{ sum = sum - val1 + val; val1 = val2; val2 = val3; val3 = val; }
	constexpr decltype(auto) get() noexcept { return sum / 3; }

private:
	double val1;
	double val2;
	double val3;
	double sum;
};

export namespace nen {
	constexpr decltype(auto) stochRSI(auto&& RSI) noexcept {
		auto iter = RSI.cbegin() + 13;
		auto size = RSI.size();

		double high, low;
		highAndLow(iter, high, low, 14);
		CalcMA calcStoch(((*iter - low) / (high - low)) * 100);
		highAndLow(++iter, high, low, 14);
		calcStoch.init2(((*iter - low) / (high - low)) * 100);
		highAndLow(++iter, high, low, 14);
		calcStoch.init3(((*iter - low) / (high - low)) * 100);

		CalcMA calcMaStoch(calcStoch.get());
		highAndLow(++iter, high, low, 14);
		calcStoch.insert(((*iter - low) / (high - low)) * 100);
		calcMaStoch.init2(calcStoch.get());
		highAndLow(++iter, high, low, 14);
		calcStoch.insert(((*iter - low) / (high - low)) * 100);
		auto get = calcStoch.get();
		calcMaStoch.init3(get);

		twv_t ret{ TwoVal(get, calcMaStoch.get()) }; ret.reserve(size - 17);

		for (auto i = 0; i < size - 18; i++) {
			highAndLow(++iter, high, low, 14);
			calcStoch.insert(((*iter - low) / (high - low)) * 100);
			get = calcStoch.get();
			calcMaStoch.insert(get);
			ret.emplace_back(TwoVal(get, calcMaStoch.get()));
		}
		return ret;
	}
}
