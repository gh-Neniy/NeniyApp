export module Analysis:BuyKDJ;

import Indicator;
import DatProc;

#define D get2()
#define J get3()

export namespace nen {
	constexpr decltype(auto) buyKDJ(const NCore<parsed_t>& core) noexcept {
		const auto _KDJ = KDJ(core);
		auto kdj = --_KDJ.cend(), kdj_1 = kdj - 1;

		if (kdj->J <= 50 && kdj->J > kdj->D && kdj_1->J < kdj_1->D) { return true; }
		return false;
	}
}
