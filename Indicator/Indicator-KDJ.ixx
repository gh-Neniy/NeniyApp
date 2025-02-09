export module Indicator:KDJ;

import :HighAndLow;
import DatProc;
import :Value;

export namespace nen {
	constexpr decltype(auto) KDJ(const NCore<parsed_t>& core) noexcept {
		auto iter = core.begin() + 8;
		double high, low;
		highAndLow(iter, high, low, 9);

		auto RSV = ((iter->price() - low) / (high - low)) * 100;
		auto K = (2.0 / 3) * 50 + (1.0 / 3) * RSV;
		auto D = (2.0 / 3) * 50 + (1.0 / 3) * K;
		auto J = 3 * K - 2 * D;

		val_t ret{ Value(K, D, J) }; ret.reserve(core.size() - 8);

		for (auto i = 0; i < core.size() - 9; i++) {
			highAndLow(++iter, high, low, 9);

			RSV = ((iter->price() - low) / (high - low)) * 100;
			K = (2.0 / 3) * K + (1.0 / 3) * RSV;
			D = (2.0 / 3) * D + (1.0 / 3) * K;
			J = 3 * K - 2 * D;
			ret.emplace_back(Value(K, D, J));
		}
		return ret;
	}
}
