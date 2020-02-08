#ifndef TRADESUMMARIZER_TRADE_SUMMARY_H
#define TRADESUMMARIZER_TRADE_SUMMARY_H

#include <string>
#include "util.h"
#include "trade_info.h"
#include "weighted_average_price.h"

namespace tradesummarizer {

// Holds output information for a single symbol.
// Also contains functions to update the summary based on new information i.e. another trade for the same symbol
// and output the information in the format specified in instructions.txt.
class TradeSummary {
public:
    TradeSummary(TradeInfoConstRef first_trade_info);

    // Should be called for each new trade reported for the instrument
    void UpdateTradeSummary(TradeInfoConstRef next_trade);

    std::string GetCommaSeparatedTradeSummary() const;
    unsigned long long GetMaxTimeGap() const {return max_time_gap_;}
    unsigned long GetWeightedAveragePrice() {return weighted_average_price_.GetWeightedAveragePrice();}
    unsigned long GetVolume() const {return volume_;}
    unsigned long GetMaxPrice() const {return max_price_;}

private:
    unsigned long long max_time_gap_ = 0; // Since it's technically possible for the time gap to midnight to a mic before the next day, the max value is 86400000000
    unsigned long max_price_ = 0;
    WeightedAveragePrice weighted_average_price_;
    unsigned long long prior_trade_timestamp_; // The timestamp of the last seen trade to calculate the time gap on new trade reported
    unsigned long volume_;
    std::string symbol_;
};

} //namespace tradesummarizer

#endif //TRADESUMMARIZER_TRADE_SUMMARY_H