export module NSocket:Req;

#include "Includes.h"
import Parts;
import std;

export namespace nen {
	inline void sendReq(SSL* ssl, std::string&& request) noexcept
	{ SSL_write(ssl, std::move(request.c_str()), static_cast<int>(request.size())); }

	constexpr inline decltype(auto) reqClose() noexcept
	{ return "HEAD / HTTP/1.1\r\nHost: api3.binance.com:443\r\nConnection: Close\r\nUser-Agent: NeniyApp\r\n\r\n"; }

	template<typename S, typename I>
	constexpr inline decltype(auto) reqKlines(S&& symbol, I&& interval) noexcept {
		return "GET /api/v3/klines?symbol=" + optS(std::forward<S>(symbol)) + "USDT&interval=" + optI(std::forward<I>(interval)) +
					"&limit=250 HTTP/1.1\r\nHost: api3.binance.com:443\r\nConnection: Keep-Alive\r\nUser-Agent: NeniyApp\r\n\r\n";
	}
}
