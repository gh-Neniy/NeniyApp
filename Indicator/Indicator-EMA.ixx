export module Indicator:EMA;

import DatProc;
import std;

export namespace nen {
	constexpr decltype(auto) EMA(const NCore<parsed_t>& core, const unsigned int period) noexcept {
		const double alpha = 2.0 / (period + 1);

		auto iter = core.begin();
		auto sum = (iter++)->price();

		for (auto i = 1U; i < period; i++)
		{ sum += (iter++)->price(); }
		
		auto calcingValue = (iter++)->price() * alpha + (1 - alpha) * (sum / period);
		std::vector<double> ret{ calcingValue }; ret.reserve(core.size() - period);

		for (auto i = 0; i < core.size() - period - 1U; i++) {
			calcingValue = (iter++)->price() * alpha + (1 - alpha) * calcingValue;

			ret.push_back(calcingValue);
		}
		return ret;
	}
}
