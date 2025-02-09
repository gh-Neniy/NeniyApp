export module Analysis:BuyStochRSI;

import Indicator;
import DatProc;
import std;

export namespace nen
{
	template<typename T> constexpr decltype(auto) buyStochRSI(T&& RSI) noexcept
	{
		const auto _stochRSI = stochRSI(std::forward<T>(RSI));
		auto iter = --_stochRSI.cend(), iter_1 = iter - 1;


		if (iter->get1() <= 20 && iter->get1() > iter->get2() && iter_1->get1() < iter_1->get2()) { return true; }
		return false;
	}
}
