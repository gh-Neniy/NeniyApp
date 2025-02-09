export module Indicator:MA;

import DatProc;
import std;

export namespace nen {
	constexpr decltype(auto) MA(const NCore<parsed_t>& core, const unsigned int period) noexcept {
		auto iter = core.begin();
		auto sum = iter->price();
		auto iterPeriod = iter + 1;

		for (auto i = 1U; i < period; i++)
		{ sum += (iterPeriod++)->price(); }

		std::vector<double> ret{ sum / period }; ret.reserve(core.size() - period + 1U);

		for (auto i = 0; i < core.size() - period; i++) {
			sum -= (iter++)->price();
			sum += (iterPeriod++)->price();

			ret.emplace_back(sum / period);
		}
		return ret;
	}
}
