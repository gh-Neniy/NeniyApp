export module NSocket:Receive;

#include "Includes.h"
import std;

export namespace nen
{
	decltype(auto) receive(auto ssl) noexcept
	{
		auto buf = std::make_unique<char[]>(16384); std::string resp;

		do {
			auto bytes_received = SSL_read(ssl, buf.get(), sizeof(char) * 16384);
			resp.append(buf.get(), bytes_received);
		} while (resp.substr(resp.size() - 2, 2) != "]]");

		return resp;
	}
}
