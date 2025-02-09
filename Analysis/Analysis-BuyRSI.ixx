export module Analysis:BuyRSI;

import Indicator;
import DatProc;

export namespace nen
{
	constexpr decltype(auto) buyRSI(const NCore<parsed_t>& core) noexcept
	{
		if (RSI(core, 7).back() <= 30) { return true; }
		return false;
	}
}
