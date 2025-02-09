export module NSocket:Clean;

#include "Includes.h"

export namespace nen {
	inline void clean(auto& sock, auto ssl) noexcept
	{ SSL_shutdown(ssl); closesocket(sock); SSL_free(ssl); }
}
