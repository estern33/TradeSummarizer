#include <stdexcept>
#include <regex>
#include "quantity_at_price.h"
#include "trade_info.h"

using namespace std;

namespace tradesummarizer {

TradeInfo TradeInfo::ParseTradeInfo(string trade_string) {
    if (trade_string.empty())
        throw invalid_argument(
                "Trade info string passed in to ParseTradeInfo was empty.  Must contain four comma separated values, refer to instructions.txt.");
    // Regex with four capture groups, matching the csv format timestamp,symbol,quantity,price
    const regex csv_regex("^(\\d+),([a-zA-Z]+),(\\d+),(\\d+)[\r\n]*$");
    smatch match;

    if (regex_search(trade_string, match, csv_regex)) {
        auto timestamp = stoll(match.str(1));
        auto symbol = match.str(2);
        QuantityAtPrice quantity_at_price(stoi(match.str(3)), stoi(match.str(4)));

        if (timestamp < 0)
            throw invalid_argument(
                    "Failed to parse trade from csv file.  Expected timestamp to always be positive.  Received " + to_string(timestamp));
        if (timestamp > 86400000000)
            throw invalid_argument(
                    "Failed to parse trade from csv file.  Expected timestamp to not exceed 24 hours.  Received " + to_string(timestamp));
        // considered checking symbol empty, but no need as the regex would not match

        return TradeInfo(symbol, timestamp, quantity_at_price);
    }

    throw invalid_argument("Failed to parse trade from csv file.  Expected timestamp,symbol,quantity,price.  Received " + trade_string);
}

TradeInfo::TradeInfo(std::string symbol, unsigned long long timestamp, const QuantityAtPrice &quantity_at_price) :
        symbol_(symbol), timestamp_(timestamp), quantity_at_price_(quantity_at_price) {}

}