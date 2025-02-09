export module NSocket:Init;

#include "Includes.h"

export namespace nen {
	inline void init() noexcept {
		WSADATA d;			WSAStartup(MAKEWORD(2, 2), &d);
		SSL_library_init(); OpenSSL_add_all_algorithms();
	}

	inline decltype(auto) initSock() noexcept {
		addrinfo hint(0); hint.ai_socktype = SOCK_STREAM;

		addrinfo* peer; getaddrinfo("api3.binance.com", "443", &hint, &peer);

		auto sock = socket(peer->ai_family, peer->ai_socktype, peer->ai_protocol);
		connect(sock, peer->ai_addr, 16);
		freeaddrinfo(peer);

		return sock;
	}

	inline decltype(auto) initSSL(const auto& sock) noexcept {
		auto ctx = SSL_CTX_new(TLS_client_method()); auto ssl = SSL_new(ctx);

		SSL_set_tlsext_host_name(ssl, "api3.binance.com");

		SSL_set_fd(ssl, static_cast<int>(sock)); SSL_connect(ssl); SSL_CTX_free(ctx);
		return ssl;
	}
}
