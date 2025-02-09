export module Indicator:BOLL;

import DatProc;
import :Value;
import :MA;
import std;

export namespace nen {
	constexpr decltype(auto) BOLL(const NCore<parsed_t>& core) noexcept {
		auto MA21 = MA(core, 21);
		auto iter = core.begin() + 20;
		val_t ret; ret.reserve(core.size() - 20U);

		for (auto&& mid : MA21) {
			auto dev = std::pow(iter->price() - mid, 2);
			for (auto i = 0; i < 20; i++) { dev += std::pow((--iter)->price() - mid, 2); } dev = std::sqrt(dev / 21);
			iter += 21;

			ret.emplace_back(Value(mid + dev * 2, mid, mid - dev * 2));
		}
		return ret;
	}
}
