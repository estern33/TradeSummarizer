#ifndef TRADESUMMARIZER_TRADE_INFO_H
#define TRADESUMMARIZER_TRADE_INFO_H

#include <string>
#include "quantity_at_price.h"

namespace tradesummarizer {

// Immutable representation of a trade and a method to parse from string.
class TradeInfo {
public:
    // Construct trade info from the comma separated format specified in instructions.txt
    // Example: here is a row for a trade of 10 shares of aaa stock at a price of 12
    // 1234567,aaa,10,12
    static TradeInfo ParseTradeInfo(std::string trade_string);

    std::string GetSymbol() const { return symbol_; }

    unsigned long long GetTimestamp() const { return timestamp_; }

    QuantityAtPrice GetQuantityAtPrice() const { return quantity_at_price_; }

private:
    TradeInfo(std::string symbol, unsigned long long timestamp, QuantityAtPriceConstRef quantity_at_price);
    std::string symbol_;
    unsigned long long timestamp_; // Timestamp from file, as represented by mics from midnight.  The max value should be 86400000000 and should therefore exceed the max value of an unsigned long.
    QuantityAtPrice quantity_at_price_;
};

using TradeInfoConstRef = as_constref<TradeInfo>::type;

} //namespace tradesummarizer

#endif //TRADESUMMARIZER_TRADE_INFO_H