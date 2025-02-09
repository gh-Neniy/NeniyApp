export module Indicator:HighAndLow;

import DatProc;

export namespace nen {
	constexpr inline void highAndLow(parsed_t::const_iterator iter, double& high, double& low, const unsigned int period) noexcept {
		high = iter->max();
		low  = iter->min();

		for (auto i = 1U; i < period; i++) {
			if ((--iter)->max() > high) { high = iter->max(); }
			if (iter->min() < low)		{ low  = iter->min(); }
		}
	}
	constexpr inline void highAndLow(std::vector<double>::const_iterator iter, double& high, double& low, const unsigned int period) noexcept {
		high = *iter;
		low = *iter;

		for (auto i = 1U; i < period; i++) {
			if (*(--iter) > high)	{ high = *iter;	}
			if (*iter < low)		{ low  = *iter;	}
		}
	}
}
