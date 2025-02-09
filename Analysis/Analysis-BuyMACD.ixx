export module Analysis:BuyMACD;

import Indicator;
import DatProc;

export namespace nen {
	constexpr decltype(auto) buyMACD(const NCore<parsed_t>& core) noexcept {
		auto _MACD = MACD(core);
		auto macd = --_MACD.end();

    return macd->get3() > (--macd)->get3() && macd->get3() < (--macd)->get3();
	}
}
