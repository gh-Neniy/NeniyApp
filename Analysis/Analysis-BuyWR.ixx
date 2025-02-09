export module Analysis:BuyWR;

import Indicator;
import DatProc;

export namespace nen {
	constexpr decltype(auto) buyWR(const NCore<parsed_t>& core) noexcept {
		const auto _WR = WR(core);
		auto wr = --_WR.cend();

		if (*wr > -80 && *wr < -50 && *(--wr) <= -80) { return true; }
		return false;
	}
}
