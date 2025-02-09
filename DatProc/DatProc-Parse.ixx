export module DatProc:Parse;

import :Kline;
import std;

export namespace nen {
	using parsed_t = std::vector<Kline>;

	template <typename Str> constexpr decltype(auto) parse(Str&& resp) noexcept {
		auto iter = resp.cbegin() + (resp.find('[') + 1);
		parsed_t ret; ret.reserve(250);

		strKline kl;
		do {
			for (int i = 0; i < 2; ++i) { do { iter++; } while (*iter != ','); } iter += 2; // Ïåðåõîä ê max

			do { kl.pushMax(*iter); iter++; } while (*iter != '\"'); iter += 3; // Ïåðåõîä ê min
			do { kl.pushMin(*iter); iter++; } while (*iter != '\"'); iter += 3; // Ïåðåõîä ê price
			do { kl.pushPrice(*iter); iter++; } while (*iter != '\"');
			do { iter++; } while (*iter != ']'); iter++;

			ret.emplace_back(Kline(kl)); kl.clear();
		} while (*iter != ']');

		ret.shrink_to_fit(); return ret;
	}
}
