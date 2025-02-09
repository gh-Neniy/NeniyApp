export module NSocket;

export import Parts;
import :Init;
import :Req;
import :Receive;
import :Clean;
import std;

export namespace nen {
class NSocket {
 public:
  NSocket() noexcept : sock(checkInitSock()), ssl(initSSL(sock)) {
    initedCount++;
  }

  NSocket(const NSocket&) = delete;
  NSocket(NSocket&&) = delete;
  NSocket& operator=(const NSocket&) = delete;
  NSocket& operator=(NSocket&&) = delete;

  ~NSocket() noexcept {
    close();
    clean(sock, ssl);
    initedCount--;
    if (!initedCount) {
      WSACleanup();
    }
  }

  template <typename S, typename I>
  decltype(auto) req(S&& symbol, I&& interval) noexcept {
    sendReq(ssl, reqKlines(std::forward<S>(symbol), std::forward<I>(interval)));
    return receive(ssl);
  }

 private:
  static unsigned int initedCount;
  SOCKET sock;
  SSL* ssl;

  void close() noexcept { sendReq(ssl, reqClose()); }

  decltype(auto) checkInitSock() noexcept {
    if (!initedCount) {
      init();
    }
    return initSock();
  }
};
unsigned int NSocket::initedCount = 0;
}  // namespace nen
