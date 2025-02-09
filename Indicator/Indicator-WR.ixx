export module Indicator:WR;

import :HighAndLow;
import DatProc;
import std;

export namespace nen {
	constexpr decltype(auto) WR(const NCore<parsed_t>& core) noexcept {
		auto iter = core.begin() + 13;
		double high, low;
		highAndLow(iter, high, low, 14);

		std::vector<double> ret{ (((iter++)->price() - high) / (high - low)) * 100 }; ret.reserve(core.size() - 13);

		for (auto i = 0; i < core.size() - 14; i++) {
			highAndLow(iter, high, low, 14);
			ret.emplace_back((((iter++)->price() - high) / (high - low)) * 100);
		}
		return ret;
	}
}
