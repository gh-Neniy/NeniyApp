export module Analysis:BuyBOLL;

import Indicator;
import DatProc;

export namespace nen {
	constexpr decltype(auto) buyBOLL(const NCore<parsed_t>& core) noexcept {
		const auto _BOLL = BOLL(core);
		auto boll = --_BOLL.cend();
		auto iter = core.end() - 1;

		if (iter->price() > boll->get2()) {
			if ((--boll)->get2() < (++boll)->get2()) {
				if ((--iter)->price() > (++iter)->price()) {
					if (iter->min() < boll->get2()) {
						if (iter->price() < (iter->min() + iter->max()) / 2) { return true; }
					}
				}
			}
		} else { // price < mid
			if (iter->min() < boll->get3())
			{
				if (iter->price() < (iter->min() + iter->max()) / 2) { return true; }
			} else { // min > down
				if (iter->min() < boll->get2() - ((boll->get2() - boll->get3()) / 3) * 2)
				{
					if (iter->price() < (iter->min() + iter->max()) / 2) { return true; }
				}
			}
		}
		return false;
	}
}
