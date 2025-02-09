export module Indicator:MACD;

import DatProc;
import :Value;
import :EMA;

export namespace nen {
	constexpr decltype(auto) MACD(const NCore<parsed_t>& core) noexcept {
		auto EMA12 = EMA(core, 12);
		auto EMA26 = EMA(core, 26);

		auto iter12 = EMA12.cbegin() + 14;
		auto iter26 = EMA26.cbegin();

		auto secondLine = *(iter12++) - *(iter26++);
		for (auto i = 0; i < 7; i++) { secondLine += *(iter12++) - *(iter26++); }
		auto firstLine = *(iter12++) - *(iter26++);
		secondLine = (secondLine + firstLine) / 9;

		val_t ret{ Value(firstLine, secondLine, firstLine - secondLine) }; ret.reserve(EMA26.size() - 8);

		auto range = EMA26.size() - 9;
		for (auto i = 0; i < range; i++) {
			firstLine = *(iter12++) - *(iter26++);
			secondLine = firstLine * 0.2 + 0.8 * secondLine;
			ret.emplace_back(Value(firstLine, secondLine, firstLine - secondLine));
		}
		return ret;
	}
}
