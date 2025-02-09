import NSocket;
import DatProc;
import Indicator;
import Analysis;
import std;

int main() {
	using namespace nen;
	NSocket s1;
	NCore<parsed_t> core;
	NCore<parsed_t> core_1;

	auto temp = parse(s1.req(Symbol::BTC, Interval::Day));
	core.set(temp);
	temp.pop_back();
	core_1.set(temp);

	auto rs_1 = RSI(core, 14), rs = rs_1;
	rs_1.pop_back();

	std::cout << "BTC" <<
		"\tBOLL=" << (buyBOLL(core) || buyBOLL(core_1)) << " [" <<
		"MA=" << buyMA(core) << ' ' <<
		"MACD=" << buyMACD(core) << "] " <<
		"StochRSI=" << (buyStochRSI(rs) || buyStochRSI(rs_1)) << ' ' <<
		"WR=" << buyWR(core) << ' ' <<
		"KDJ=" << buyKDJ(core) << ' ' <<
		"RSI=" << buyRSI(core) << "\t\t" << (core.end() - 1)->price() << "\n\n";

	for (auto s = Symbol::INCH; s != Symbol::End; ++s) {
		temp = parse(s1.req(s, Interval::Day));
		core.set(temp);
		temp.pop_back();
		core_1.set(temp);

		rs = rs_1 = RSI(core, 14);
		rs_1.pop_back();

		bool boll = buyBOLL(core) || buyBOLL(core_1), ma = buyMA(core), macd = buyMACD(core), stochRSI = buyStochRSI(rs) || buyStochRSI(rs_1),
			wr = buyWR(core), kdj = buyKDJ(core), rsi = buyRSI(core);

		std::cout << optS(s) << "\tBOLL=" << boll << " [" << "MA=" << ma << ' ' << "MACD=" << macd << "] " <<
				"StochRSI=" << stochRSI << ' ' << "WR=" << wr << ' ' << "KDJ=" << kdj << ' ' << "RSI=" << rsi << '\n';

		if ((boll && ((stochRSI || wr || kdj || rsi) || (ma && macd)))
			|| (stochRSI && wr && kdj) || (wr && kdj && rsi) || (stochRSI && kdj && rsi) || (wr && stochRSI && rsi)) {
			temp = parse(s1.req(s, Interval::FourHours));
			core.set(temp);
			temp.pop_back();
			core_1.set(temp);

			rs = rs_1 = RSI(core, 14);
			rs_1.pop_back();

			std::cout <<
				"\tBOLL=" << (buyBOLL(core) || buyBOLL(core_1)) << " [" <<
				"MA=" << buyMA(core) << ' ' <<
				"MACD=" << buyMACD(core) << "] " <<
				"StochRSI=" << (buyStochRSI(rs) || buyStochRSI(rs_1)) << ' ' <<
				"WR=" << buyWR(core) << ' ' <<
				"KDJ=" << buyKDJ(core) << ' ' <<
				"RSI=" << buyRSI(core) << "\n\n";
		}
	}
	system("pause");
	return 0;
}
