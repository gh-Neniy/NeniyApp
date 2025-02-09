export module DatProc:Kline;

import std;

export namespace nen {
	class strKline {
	public:
		constexpr strKline() noexcept
			: strPrice(), strMin(), strMax() {}

		constexpr ~strKline() noexcept = default;
		
		constexpr void pushPrice(const char character)	noexcept { strPrice.push_back(character);	}
		constexpr void pushMin(const char character)	noexcept { strMin.push_back(character);		}
		constexpr void pushMax(const char character)	noexcept { strMax.push_back(character);		}

		decltype(auto) price()	const noexcept { return std::stod(strPrice);	}
		decltype(auto) min()	const noexcept { return std::stod(strMin);		}
		decltype(auto) max()	const noexcept { return std::stod(strMax);		}

		constexpr void clear() noexcept { strPrice.clear(); strMin.clear(); strMax.clear(); }

	private:
		std::string strPrice;
		std::string strMin;
		std::string strMax;
	};

	class Kline {
	public:
		constexpr Kline() noexcept
			: _price(), _min(), _max() {}
		template<typename strKl> constexpr Kline(strKl&& kl) noexcept
			:	_price(kl.price()), _min(kl.min()), _max(kl.max()) {}

		constexpr ~Kline() noexcept = default;

		constexpr decltype(auto) price() const noexcept { return _price; }
		constexpr decltype(auto) min()	 const noexcept { return _min;	 }
		constexpr decltype(auto) max()	 const noexcept { return _max;	 }

	private:
		double _price;
		double _min;
		double _max;
	};
}
