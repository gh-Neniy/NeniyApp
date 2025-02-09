export module Analysis:BuyMA;

import Indicator;
import DatProc;

export namespace nen {
	constexpr decltype(auto) buyMA(const NCore<parsed_t>& core) noexcept {
		auto ma25  = MA(core, 25).back();
		auto ma50  = MA(core, 50).back();
		auto ma100 = MA(core, 100).back();
		auto iter = core.end() - 1;

		if (iter->price() > ma25) {
			if (iter->min() < ma25)											{ return true; }
			else if (iter->min() - ma25 <= (iter->max() - iter->min()) / 2) { return true; }
		}
		if (iter->price() > ma50) {
			if (iter->min() < ma50)											{ return true; }
			else if (iter->min() - ma50 <= (iter->max() - iter->min()) / 2) { return true; }
		}
		if (iter->price() > ma100) {
			if (iter->min() < ma100)										 { return true; }
			else if (iter->min() - ma100 <= (iter->max() - iter->min()) / 2) { return true; }
		}
		return false;
	}
}
