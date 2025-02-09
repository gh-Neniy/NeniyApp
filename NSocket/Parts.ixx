export module Parts;

import std;

export namespace nen
{
	enum class Symbol
	{
		INCH,	AAVE,	ACM,	ADA,	ADX,	AGLD,	AKRO,	ALGO,	ALICE,	ALPACA,	ALPHA,	ANKR,	ANT,	ARDR,	ARPA,	AR,		ASR,
		ATA,	ATM,	ATOM,	AUCTION,AUDIO,	AVA,	AVAX,	AXS,	BADGER,	BAKE,	BAL,	BAND,	BAR,	BAT,	BCH,	BEL,	BETA,
		BLZ,	BNB,	BNT,	BOND,	BTC,	BTS,	BURGER,	C98,	CAKE,	CELO,	CELR,	CFX,	CHESS,	CHR,	CHZ,	CITY,	CKB,
		CLV,	COMP,	COS,	COTI,	CRV,	CTK,	CTSI,	CTXC,	CVC,	CVP,	DAR,	DASH,	DATA,	DCR,	DEGO,	DENT,	DEXE,
		DF,		DGB,	DIA,	DOCK,	DODO,	DOGE,	DOT,	DREP,	DUSK,	DYDX,	EGLD,	ELF,	ENJ,	ENS,	EOS,	ERN,	ETC,
		ETH,	FARM,	FET,	FIDA,	FIL,	FIO,	FIRO,	FIS,	FLM,	FLOW,	FORTH,	FOR,	FRONT,	FTM,	FTT,	FUN,	GALA,
		GBP,	GHST,	GNO,	GRT,	GTC,	HARD,	HBAR,	HIVE,	HOT,	ICP,	ICX,	IDEX,	ILV,	INJ,	IOST,	IOTA,	IOTX,
		IRIS,	JST,	JUV,	KAVA,	KEY,	KLAY,	KMD,	KNC,	KP3R,	KSM,	LAZIO,	LINA,	LINK,	LIT,	LPT,	LRC,	LSK,
		LTC,	LTO,	LUNA,	MANA,	MASK,	MATIC,	MBL,	MBOX,	MDT,	MDX,	MINA,	MKR,	MLN,	MOVR,	MTL,	NEAR,	NEO,
		NKN,	NMR,	NULS,	OCEAN,	OGN,	OG,		OMG,	OM,		ONE,	ONG,	ONT,	ORN,	OXT,	PAXG,	PERL,	PERP,	PHA,
		PNT,	POLS,	POND,	PORTO,	POWR,	PSG,	PUNDIX,	QI,		QNT,	QTUM,	RAD,	RARE,	RAY,	REEF,	REN,	REQ,	RIF,
		RLC,	ROSE,	RSR,	RUNE,	RVN,	SAND,	SC,		SFP,	SHIB,	SKL,	SLP,	SNX,	SOL,	STMX,	STORJ,	STPT,	STRAX,
		STX,	SUN,	SUPER,	SUSHI,	SXP,	SYS,	TFUEL,	THETA,	TKO,	TLM,	TOMO,	TRB,	TROY,	TRU,	TRX,	TVK,	TWT,
		UMA,	UNFI,	UNI,	UTK,	VET,	VIDT,	VITE,	VTHO,	WAN,	WAVES,	WING,	WIN,	WNXM,	WRX,	WTC,	XEC,	XEM,
		XLM,	XMR,	XRP,	XTZ,	XVG,	XVS,	YFI,	YGG,	ZEC,	ZEN,	ZIL,	ZRX,

		End
	};
	enum class Interval
	{
		FiveMinutes,
		FifteenMinutes,
		FourHours,
		SixHours,
		EightHours,
		TwentyHours,
		Day,
		ThreeDays,
		Week
	};

	constexpr inline void operator++(Symbol& symbol) noexcept				 { symbol = static_cast<Symbol>(static_cast<int>(symbol) + 1);	 }
	constexpr inline void operator+=(Symbol& symbol, const int val) noexcept { symbol = static_cast<Symbol>(static_cast<int>(symbol) + val); }

	template<typename S> constexpr inline std::string optS(S&& symbol) noexcept
	{
		switch (std::forward<S>(symbol))
		{
		case Symbol::INCH:		return "1INCH";
		case Symbol::AAVE:		return "AAVE";
		case Symbol::ACM:		return "ACM";
		case Symbol::ADA:		return "ADA";
		case Symbol::ADX:		return "ADX";
		case Symbol::AGLD:		return "AGLD";
		case Symbol::AKRO:		return "AKRO";
		case Symbol::ALGO:		return "ALGO";
		case Symbol::ALICE:		return "ALICE";
		case Symbol::ALPACA:	return "ALPACA";
		case Symbol::ALPHA:		return "ALPHA";
		case Symbol::ANKR:		return "ANKR";
		case Symbol::ANT:		return "ANT";
		case Symbol::ARDR:		return "ARDR";
		case Symbol::ARPA:		return "ARPA";
		case Symbol::AR:		return "AR";
		case Symbol::ASR:		return "ASR";
		case Symbol::ATA:		return "ATA";
		case Symbol::ATM:		return "ATM";
		case Symbol::ATOM:		return "ATOM";
		case Symbol::AUCTION:	return "AUCTION";
		case Symbol::AUDIO:		return "AUDIO";
		case Symbol::AVA:		return "AVA";
		case Symbol::AVAX:		return "AVAX";
		case Symbol::AXS:		return "AXS";
		case Symbol::BADGER:	return "BADGER";
		case Symbol::BAKE:		return "BAKE";
		case Symbol::BAL:		return "BAL";
		case Symbol::BAND:		return "BAND";
		case Symbol::BAR:		return "BAR";
		case Symbol::BAT:		return "BAT";
		case Symbol::BCH:		return "BCH";
		case Symbol::BEL:		return "BEL";
		case Symbol::BETA:		return "BETA";
		case Symbol::BLZ:		return "BLZ";
		case Symbol::BNB:		return "BNB";
		case Symbol::BNT:		return "BNT";
		case Symbol::BOND:		return "BOND";
		case Symbol::BTC:		return "BTC";
		case Symbol::BTS:		return "BTS";
		case Symbol::BURGER:	return "BURGER";
		case Symbol::C98:		return "C98";
		case Symbol::CAKE:		return "CAKE";
		case Symbol::CELO:		return "CELO";
		case Symbol::CELR:		return "CELR";
		case Symbol::CFX:		return "CFX";
		case Symbol::CHESS:		return "CHESS";
		case Symbol::CHR:		return "CHR";
		case Symbol::CHZ:		return "CHZ";
		case Symbol::CITY:		return "CITY";
		case Symbol::CKB:		return "CKB";
		case Symbol::CLV:		return "CLV";
		case Symbol::COMP:		return "COMP";
		case Symbol::COS:		return "COS";
		case Symbol::COTI:		return "COTI";
		case Symbol::CRV:		return "CRV";
		case Symbol::CTK:		return "CTK";
		case Symbol::CTSI:		return "CTSI";
		case Symbol::CTXC:		return "CTXC";
		case Symbol::CVC:		return "CVC";
		case Symbol::CVP:		return "CVP";
		case Symbol::DAR:		return "DAR";
		case Symbol::DASH:		return "DASH";
		case Symbol::DATA:		return "DATA";
		case Symbol::DCR:		return "DCR";
		case Symbol::DEGO:		return "DEGO";
		case Symbol::DENT:		return "DENT";
		case Symbol::DEXE:		return "DEXE";
		case Symbol::DF:		return "DF";
		case Symbol::DGB:		return "DGB";
		case Symbol::DIA:		return "DIA";
		case Symbol::DOCK:		return "DOCK";
		case Symbol::DODO:		return "DODO";
		case Symbol::DOGE:		return "DOGE";
		case Symbol::DOT:		return "DOT";
		case Symbol::DREP:		return "DREP";
		case Symbol::DUSK:		return "DUSK";
		case Symbol::DYDX:		return "DYDX";
		case Symbol::EGLD:		return "EGLD";
		case Symbol::ELF:		return "ELF";
		case Symbol::ENJ:		return "ENJ";
		case Symbol::ENS:		return "ENS";
		case Symbol::EOS:		return "EOS";
		case Symbol::ERN:		return "ERN";
		case Symbol::ETC:		return "ETC";
		case Symbol::ETH:		return "ETH";
		case Symbol::FARM:		return "FARM";
		case Symbol::FET:		return "FET";
		case Symbol::FIDA:		return "FIDA";
		case Symbol::FIL:		return "FIL";
		case Symbol::FIO:		return "FIO";
		case Symbol::FIRO:		return "FIRO";
		case Symbol::FIS:		return "FIS";
		case Symbol::FLM:		return "FLM";
		case Symbol::FLOW:		return "FLOW";
		case Symbol::FORTH:		return "FORTH";
		case Symbol::FOR:		return "FOR";
		case Symbol::FRONT:		return "FRONT";
		case Symbol::FTM:		return "FTM";
		case Symbol::FTT:		return "FTT";
		case Symbol::FUN:		return "FUN";
		case Symbol::GALA:		return "GALA";
		case Symbol::GBP:		return "GBP";
		case Symbol::GHST:		return "GHST";
		case Symbol::GNO:		return "GNO";
		case Symbol::GRT:		return "GRT";
		case Symbol::GTC:		return "GTC";
		case Symbol::HARD:		return "HARD";
		case Symbol::HBAR:		return "HBAR";
		case Symbol::HIVE:		return "HIVE";
		case Symbol::HOT:		return "HOT";
		case Symbol::ICP:		return "ICP";
		case Symbol::ICX:		return "ICX";
		case Symbol::IDEX:		return "IDEX";
		case Symbol::ILV:		return "ILV";
		case Symbol::INJ:		return "INJ";
		case Symbol::IOST:		return "IOST";
		case Symbol::IOTA:		return "IOTA";
		case Symbol::IOTX:		return "IOTX";
		case Symbol::IRIS:		return "IRIS";
		case Symbol::JST:		return "JST";
		case Symbol::JUV:		return "JUV";
		case Symbol::KAVA:		return "KAVA";
		case Symbol::KEY:		return "KEY";
		case Symbol::KLAY:		return "KLAY";
		case Symbol::KMD:		return "KMD";
		case Symbol::KNC:		return "KNC";
		case Symbol::KP3R:		return "KP3R";
		case Symbol::KSM:		return "KSM";
		case Symbol::LAZIO:		return "LAZIO";
		case Symbol::LINA:		return "LINA";
		case Symbol::LINK:		return "LINK";
		case Symbol::LIT:		return "LIT";
		case Symbol::LPT:		return "LPT";
		case Symbol::LRC:		return "LRC";
		case Symbol::LSK:		return "LSK";
		case Symbol::LTC:		return "LTC";
		case Symbol::LTO:		return "LTO";
		case Symbol::LUNA:		return "LUNA";
		case Symbol::MANA:		return "MANA";
		case Symbol::MASK:		return "MASK";
		case Symbol::MATIC:		return "MATIC";
		case Symbol::MBL:		return "MBL";
		case Symbol::MBOX:		return "MBOX";
		case Symbol::MDT:		return "MDT";
		case Symbol::MDX:		return "MDX";
		case Symbol::MINA:		return "MINA";
		case Symbol::MKR:		return "MKR";
		case Symbol::MLN:		return "MLN";
		case Symbol::MOVR:		return "MOVR";
		case Symbol::MTL:		return "MTL";
		case Symbol::NEAR:		return "NEAR";
		case Symbol::NEO:		return "NEO";
		case Symbol::NKN:		return "NKN";
		case Symbol::NMR:		return "NMR";
		case Symbol::NULS:		return "NULS";
		case Symbol::OCEAN:		return "OCEAN";
		case Symbol::OGN:		return "OGN";
		case Symbol::OG:		return "OG";
		case Symbol::OMG:		return "OMG";
		case Symbol::OM:		return "OM";
		case Symbol::ONE:		return "ONE";
		case Symbol::ONG:		return "ONG";
		case Symbol::ONT:		return "ONT";
		case Symbol::ORN:		return "ORN";
		case Symbol::OXT:		return "OXT";
		case Symbol::PAXG:		return "PAXG";
		case Symbol::PERL:		return "PERL";
		case Symbol::PERP:		return "PERP";
		case Symbol::PHA:		return "PHA";
		case Symbol::PNT:		return "PNT";
		case Symbol::POLS:		return "POLS";
		case Symbol::POND:		return "POND";
		case Symbol::PORTO:		return "PORTO";
		case Symbol::POWR:		return "POWR";
		case Symbol::PSG:		return "PSG";
		case Symbol::PUNDIX:	return "PUNDIX";
		case Symbol::QI:		return "QI";
		case Symbol::QNT:		return "QNT";
		case Symbol::QTUM:		return "QTUM";
		case Symbol::RAD:		return "RAD";
		case Symbol::RARE:		return "RARE";
		case Symbol::RAY:		return "RAY";
		case Symbol::REEF:		return "REEF";
		case Symbol::REN:		return "REN";
		case Symbol::REQ:		return "REQ";
		case Symbol::RIF:		return "RIF";
		case Symbol::RLC:		return "RLC";
		case Symbol::ROSE:		return "ROSE";
		case Symbol::RSR:		return "RSR";
		case Symbol::RUNE:		return "RUNE";
		case Symbol::RVN:		return "RVN";
		case Symbol::SAND:		return "SAND";
		case Symbol::SC:		return "SC";
		case Symbol::SFP:		return "SFP";
		case Symbol::SHIB:		return "SHIB";
		case Symbol::SKL:		return "SKL";
		case Symbol::SLP:		return "SLP";
		case Symbol::SNX:		return "SNX";
		case Symbol::SOL:		return "SOL";
		case Symbol::STMX:		return "STMX";
		case Symbol::STORJ:		return "STORJ";
		case Symbol::STPT:		return "STPT";
		case Symbol::STRAX:		return "STRAX";
		case Symbol::STX:		return "STX";
		case Symbol::SUN:		return "SUN";
		case Symbol::SUPER:		return "SUPER";
		case Symbol::SUSHI:		return "SUSHI";
		case Symbol::SXP:		return "SXP";
		case Symbol::SYS:		return "SYS";
		case Symbol::TFUEL:		return "TFUEL";
		case Symbol::THETA:		return "THETA";
		case Symbol::TKO:		return "TKO";
		case Symbol::TLM:		return "TLM";
		case Symbol::TOMO:		return "TOMO";
		case Symbol::TRB:		return "TRB";
		case Symbol::TROY:		return "TROY";
		case Symbol::TRU:		return "TRU";
		case Symbol::TRX:		return "TRX";
		case Symbol::TVK:		return "TVK";
		case Symbol::TWT:		return "TWT";
		case Symbol::UMA:		return "UMA";
		case Symbol::UNFI:		return "UNFI";
		case Symbol::UNI:		return "UNI";
		case Symbol::UTK:		return "UTK";
		case Symbol::VET:		return "VET";
		case Symbol::VIDT:		return "VIDT";
		case Symbol::VITE:		return "VITE";
		case Symbol::VTHO:		return "VTHO";
		case Symbol::WAN:		return "WAN";
		case Symbol::WAVES:		return "WAVES";
		case Symbol::WING:		return "WING";
		case Symbol::WIN:		return "WIN";
		case Symbol::WNXM:		return "WNXM";
		case Symbol::WRX:		return "WRX";
		case Symbol::WTC:		return "WTC";
		case Symbol::XEC:		return "XEC";
		case Symbol::XEM:		return "XEM";
		case Symbol::XLM:		return "XLM";
		case Symbol::XMR:		return "XMR";
		case Symbol::XRP:		return "XRP";
		case Symbol::XTZ:		return "XTZ";
		case Symbol::XVG:		return "XVG";
		case Symbol::XVS:		return "XVS";
		case Symbol::YFI:		return "YFI";
		case Symbol::YGG:		return "YGG";
		case Symbol::ZEC:		return "ZEC";
		case Symbol::ZEN:		return "ZEN";
		case Symbol::ZIL:		return "ZIL";
		case Symbol::ZRX:		return "ZRX";
		default: return "BTC";
		}
	}
	template<typename I> constexpr inline std::string optI(I&& interval) noexcept
	{
		switch (std::forward<I>(interval))
		{
		case Interval::FiveMinutes:		return "5m";
		case Interval::FifteenMinutes:	return "15m";
		case Interval::FourHours:		return "4h";
		case Interval::SixHours:		return "6h";
		case Interval::EightHours:		return "8h";
		case Interval::TwentyHours:		return "12h";
		case Interval::Day:				return "1d";
		case Interval::ThreeDays:		return "3d";
		case Interval::Week:			return "1w";
		default: return "1d";
		}
	}
	
	const std::unordered_map<std::string, Symbol> strOpt {
		{ "INCH",	Symbol::INCH	},
		{ "AAVE",	Symbol::AAVE	},
		{ "ACM",	Symbol::ACM		},
		{ "ADA",	Symbol::ADA		},
		{ "ADX",	Symbol::ADX		},
		{ "AGLD",	Symbol::AGLD	},
		{ "AKRO",	Symbol::AKRO	},
		{ "ALGO",	Symbol::ALGO	},
		{ "ALICE",	Symbol::ALICE	},
		{ "ALPACA", Symbol::ALPACA	},
		{ "ALPHA",	Symbol::ALPHA	},
		{ "ANKR",	Symbol::ANKR	},
		{ "ANT",	Symbol::ANT		},
		{ "ARDR",	Symbol::ARDR	},
		{ "ARPA",	Symbol::ARPA	},
		{ "AR",		Symbol::AR		},
		{ "ASR",	Symbol::ASR		},
		{ "ATA",	Symbol::ATA		},
		{ "ATM",	Symbol::ATM		},
		{ "ATOM",	Symbol::ATOM	},
		{ "AUCTION",Symbol::AUCTION },
		{ "AUDIO",	Symbol::AUDIO	},
		{ "AVA",	Symbol::AVA		},
		{ "AVAX",	Symbol::AVAX	},
		{ "AXS",	Symbol::AXS		},
		{ "BADGER",	Symbol::BADGER	},
		{ "BAKE",	Symbol::BAKE	},
		{ "BAL",	Symbol::BAL		},
		{ "BAND",	Symbol::BAND	},
		{ "BAR",	Symbol::BAR		},
		{ "BAT",	Symbol::BAT		},
		{ "BCH",	Symbol::BCH		},
		{ "BEL",	Symbol::BEL		},
		{ "BETA",	Symbol::BETA	},
		{ "BLZ",	Symbol::BLZ		},
		{ "BNB",	Symbol::BNB		},
		{ "BNT",	Symbol::BNT		},
		{ "BOND",	Symbol::BOND	},
		{ "BTC",	Symbol::BTC		},
		{ "BTS",	Symbol::BTS		},
		{ "BURGER",	Symbol::BURGER	},
		{ "C98",	Symbol::C98		},
		{ "CAKE",	Symbol::CAKE	},
		{ "CELO",	Symbol::CELO	},
		{ "CELR",	Symbol::CELR	},
		{ "CFX",	Symbol::CFX		},
		{ "CHESS",	Symbol::CHESS	},
		{ "CHR",	Symbol::CHR		},
		{ "CHZ",	Symbol::CHZ		},
		{ "CITY",	Symbol::CITY	},
		{ "CKB",	Symbol::CKB		},
		{ "CLV",	Symbol::CLV		},
		{ "COMP",	Symbol::COMP	},
		{ "COS",	Symbol::COS		},
		{ "COTI",	Symbol::COTI	},
		{ "CRV",	Symbol::CRV		},
		{ "CTK",	Symbol::CTK		},
		{ "CTSI",	Symbol::CTSI	},
		{ "CTXC",	Symbol::CTXC	},
		{ "CVC",	Symbol::CVC		},
		{ "CVP",	Symbol::CVP		},
		{ "DAR",	Symbol::DAR		},
		{ "DASH",	Symbol::DASH	},
		{ "DATA",	Symbol::DATA	},
		{ "DCR",	Symbol::DCR		},
		{ "DEGO",	Symbol::DEGO	},
		{ "DENT",	Symbol::DENT	},
		{ "DEXE",	Symbol::DEXE	},
		{ "DF",		Symbol::DF		},
		{ "DGB",	Symbol::DGB		},
		{ "DIA",	Symbol::DIA		},
		{ "DOCK",	Symbol::DOCK	},
		{ "DODO",	Symbol::DODO	},
		{ "DOGE",	Symbol::DOGE	},
		{ "DOT",	Symbol::DOT		},
		{ "DREP",	Symbol::DREP	},
		{ "DUSK",	Symbol::DUSK	},
		{ "DYDX",	Symbol::DYDX	},
		{ "EGLD",	Symbol::EGLD	},
		{ "ELF",	Symbol::ELF		},
		{ "ENJ",	Symbol::ENJ		},
		{ "ENS",	Symbol::ENS		},
		{ "EOS",	Symbol::EOS		},
		{ "ERN",	Symbol::ERN		},
		{ "ETC",	Symbol::ETC		},
		{ "ETH",	Symbol::ETH		},
		{ "FARM",	Symbol::FARM	},
		{ "FET",	Symbol::FET		},
		{ "FIDA",	Symbol::FIDA	},
		{ "FIL",	Symbol::FIL		},
		{ "FIO",	Symbol::FIO		},
		{ "FIRO",	Symbol::FIRO	},
		{ "FIS",	Symbol::FIS		},
		{ "FLM",	Symbol::FLM		},
		{ "FLOW",	Symbol::FLOW	},
		{ "FORTH",	Symbol::FORTH	},
		{ "FOR",	Symbol::FOR		},
		{ "FRONT",	Symbol::FRONT	},
		{ "FTM",	Symbol::FTM		},
		{ "FTT",	Symbol::FTT		},
		{ "FUN",	Symbol::FUN		},
		{ "GALA",	Symbol::GALA	},
		{ "GBP",	Symbol::GBP		},
		{ "GHST",	Symbol::GHST	},
		{ "GNO",	Symbol::GNO		},
		{ "GRT",	Symbol::GRT		},
		{ "GTC",	Symbol::GTC		},
		{ "HARD",	Symbol::HARD	},
		{ "HBAR",	Symbol::HBAR	},
		{ "HIVE",	Symbol::HIVE	},
		{ "HOT",	Symbol::HOT		},
		{ "ICP",	Symbol::ICP		},
		{ "ICX",	Symbol::ICX		},
		{ "IDEX",	Symbol::IDEX	},
		{ "ILV",	Symbol::ILV		},
		{ "INJ",	Symbol::INJ		},
		{ "IOST",	Symbol::IOST	},
		{ "IOTA",	Symbol::IOTA	},
		{ "IOTX",	Symbol::IOTX	},
		{ "IRIS",	Symbol::IRIS	},
		{ "JST",	Symbol::JST		},
		{ "JUV",	Symbol::JUV		},
		{ "KAVA",	Symbol::KAVA	},
		{ "KEY",	Symbol::KEY		},
		{ "KLAY",	Symbol::KLAY	},
		{ "KMD",	Symbol::KMD		},
		{ "KNC",	Symbol::KNC		},
		{ "KP3R",	Symbol::KP3R	},
		{ "KSM",	Symbol::KSM		},
		{ "LAZIO",	Symbol::LAZIO	},
		{ "LINA",	Symbol::LINA	},
		{ "LINK",	Symbol::LINK	},
		{ "LIT",	Symbol::LIT		},
		{ "LPT",	Symbol::LPT		},
		{ "LRC",	Symbol::LRC		},
		{ "LSK",	Symbol::LSK		},
		{ "LTC",	Symbol::LTC		},
		{ "LTO",	Symbol::LTO		},
		{ "LUNA",	Symbol::LUNA	},
		{ "MANA",	Symbol::MANA	},
		{ "MASK",	Symbol::MASK	},
		{ "MATIC",	Symbol::MATIC	},
		{ "MBL",	Symbol::MBL		},
		{ "MBOX",	Symbol::MBOX	},
		{ "MDT",	Symbol::MDT		},
		{ "MDX",	Symbol::MDX		},
		{ "MINA",	Symbol::MINA	},
		{ "MKR",	Symbol::MKR		},
		{ "MLN",	Symbol::MLN		},
		{ "MOVR",	Symbol::MOVR	},
		{ "MTL",	Symbol::MTL		},
		{ "NEAR",	Symbol::NEAR	},
		{ "NEO",	Symbol::NEO		},
		{ "NKN",	Symbol::NKN		},
		{ "NMR",	Symbol::NMR		},
		{ "NULS",	Symbol::NULS	},
		{ "OCEAN",	Symbol::OCEAN	},
		{ "OGN",	Symbol::OGN		},
		{ "OG",		Symbol::OG		},
		{ "OMG",	Symbol::OMG		},
		{ "OM",		Symbol::OM		},
		{ "ONE",	Symbol::ONE		},
		{ "ONG",	Symbol::ONG		},
		{ "ONT",	Symbol::ONT		},
		{ "ORN",	Symbol::ORN		},
		{ "OXT",	Symbol::OXT		},
		{ "PAXG",	Symbol::PAXG	},
		{ "PERL",	Symbol::PERL	},
		{ "PERP",	Symbol::PERP	},
		{ "PHA",	Symbol::PHA		},
		{ "PNT",	Symbol::PNT		},
		{ "POLS",	Symbol::POLS	},
		{ "POND",	Symbol::POND	},
		{ "PORTO",	Symbol::PORTO	},
		{ "POWR",	Symbol::POWR	},
		{ "PSG",	Symbol::PSG		},
		{ "PUNDIX",	Symbol::PUNDIX	},
		{ "QI",		Symbol::QI		},
		{ "QNT",	Symbol::QNT		},
		{ "QTUM",	Symbol::QTUM	},
		{ "RAD",	Symbol::RAD		},
		{ "RARE",	Symbol::RARE	},
		{ "RAY",	Symbol::RAY		},
		{ "REEF",	Symbol::REEF	},
		{ "REN",	Symbol::REN		},
		{ "REQ",	Symbol::REQ		},
		{ "RIF",	Symbol::RIF		},
		{ "RLC",	Symbol::RLC		},
		{ "ROSE",	Symbol::ROSE	},
		{ "RSR",	Symbol::RSR		},
		{ "RUNE",	Symbol::RUNE	},
		{ "RVN",	Symbol::RVN		},
		{ "SAND",	Symbol::SAND	},
		{ "SC",		Symbol::SC		},
		{ "SFP",	Symbol::SFP		},
		{ "SHIB",	Symbol::SHIB	},
		{ "SKL",	Symbol::SKL		},
		{ "SLP",	Symbol::SLP		},
		{ "SNX",	Symbol::SNX		},
		{ "SOL",	Symbol::SOL		},
		{ "STMX",	Symbol::STMX	},
		{ "STORJ",	Symbol::STORJ	},
		{ "STPT",	Symbol::STPT	},
		{ "STRAX",	Symbol::STRAX	},
		{ "STX",	Symbol::STX		},
		{ "SUN",	Symbol::SUN		},
		{ "SUPER",	Symbol::SUPER	},
		{ "SUSHI",	Symbol::SUSHI	},
		{ "SXP",	Symbol::SXP		},
		{ "SYS",	Symbol::SYS		},
		{ "TFUEL",	Symbol::TFUEL	},
		{ "THETA",	Symbol::THETA	},
		{ "TKO",	Symbol::TKO		},
		{ "TLM",	Symbol::TLM		},
		{ "TOMO",	Symbol::TOMO	},
		{ "TRB",	Symbol::TRB		},
		{ "TROY",	Symbol::TROY	},
		{ "TRU",	Symbol::TRU		},
		{ "TRX",	Symbol::TRX		},
		{ "TVK",	Symbol::TVK		},
		{ "TWT",	Symbol::TWT		},
		{ "UMA",	Symbol::UMA		},
		{ "UNFI",	Symbol::UNFI	},
		{ "UNI",	Symbol::UNI		},
		{ "UTK",	Symbol::UTK		},
		{ "VET",	Symbol::VET		},
		{ "VIDT",	Symbol::VIDT	},
		{ "VITE",	Symbol::VITE	},
		{ "VTHO",	Symbol::VTHO	},
		{ "WAN",	Symbol::WAN		},
		{ "WAVES",	Symbol::WAVES	},
		{ "WING",	Symbol::WING	},
		{ "WIN",	Symbol::WIN		},
		{ "WNXM",	Symbol::WNXM	},
		{ "WRX",	Symbol::WRX		},
		{ "WTC",	Symbol::WTC		},
		{ "XEC",	Symbol::XEC		},
		{ "XEM",	Symbol::XEM		},
		{ "XLM",	Symbol::XLM		},
		{ "XMR",	Symbol::XMR		},
		{ "XRP",	Symbol::XRP		},
		{ "XTZ",	Symbol::XTZ		},
		{ "XVG",	Symbol::XVG		},
		{ "XVS",	Symbol::XVS		},
		{ "YFI",	Symbol::YFI		},
		{ "YGG",	Symbol::YGG		},
		{ "ZEC",	Symbol::ZEC		},
		{ "ZEN",	Symbol::ZEN		},
		{ "ZIL",	Symbol::ZIL		},
		{ "ZRX",	Symbol::ZRX		}
	};
}
