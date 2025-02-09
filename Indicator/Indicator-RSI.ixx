export module Indicator:RSI;

import DatProc;
import :Value;
import std;

constexpr decltype(auto) MMA(const std::vector<double>& vec, const unsigned int period) noexcept {
	auto iter = vec.cbegin();
	auto val = *(iter++);

	for (auto i = 1U; i < period; i++)
	{ val += *(iter++); }
	val = val / period;

	auto size = vec.size();
	std::vector<double> ret { val }; ret.reserve(size - period + 1U);

	for (auto i = 0; i < size - period; i++)
	{
		val = (*(iter++) + (period - 1) * val) / period;
		ret.push_back(val);
	}
	return ret;
}

export namespace nen {
	constexpr decltype(auto) RSI(const NCore<parsed_t>& core, const unsigned int period) noexcept {
		std::pair<std::vector<double>, std::vector<double>> UD;
		UD.first.reserve(core.size() - 1); UD.second.reserve(core.size() - 1);
		auto t_1 = core.begin(), t = t_1 + 1;

		for (auto i = 0; i < core.size() - 1; i++)
		{
			if (t_1->price() < t->price())
			{
				UD.first.emplace_back((t++)->price() - (t_1++)->price());
				UD.second.emplace_back(0);
			} else {
				UD.first.emplace_back(0);
				UD.second.emplace_back((t_1++)->price() - (t++)->price());
			}
		}

		UD.first = MMA(UD.first,  period); UD.second = MMA(UD.second, period);
		std::vector<double> ret; ret.reserve(UD.first.size());
		auto down = UD.second.cbegin();

		for(auto&& up : UD.first) { ret.emplace_back(100 - (100 / (1 + up / *(down++)))); }

		return ret;
	}
}
