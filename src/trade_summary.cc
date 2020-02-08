#include <stdexcept>
#include <regex>
#include "quantity_at_price.h"
#include "trade_info.h"
#include "trade_summary.h"
#include "util.h"

using namespace std;

namespace tradesummarizer {

TradeSummary::TradeSummary(TradeInfoConstRef first_trade_info) {
    prior_trade_timestamp_ = first_trade_info.GetTimestamp();
    weighted_average_price_.AddTrade(first_trade_info.GetQuantityAtPrice());
    symbol_ = first_trade_info.GetSymbol();
    volume_ = first_trade_info.GetQuantityAtPrice().GetQuantity();
    max_price_ = first_trade_info.GetQuantityAtPrice().GetPrice();
}

// Should be called for each new trade reported for the instrument
void TradeSummary::UpdateTradeSummary(TradeInfoConstRef next_trade) {
    if (next_trade.GetTimestamp() < prior_trade_timestamp_)
        throw invalid_argument("Timestamps should always be progressing in the trade stream, "
                               "but received a negative time gap from " + to_string(prior_trade_timestamp_) +
                               " to " + to_string(next_trade.GetTimestamp()));

    auto current_time_gap = next_trade.GetTimestamp() - prior_trade_timestamp_;

    if (current_time_gap > max_time_gap_)
        max_time_gap_ = current_time_gap;

    prior_trade_timestamp_ = next_trade.GetTimestamp();
    volume_ += next_trade.GetQuantityAtPrice().GetQuantity();
    if (next_trade.GetQuantityAtPrice().GetPrice() > max_price_)
        max_price_ = next_trade.GetQuantityAtPrice().GetPrice();
    weighted_average_price_.AddTrade(next_trade.GetQuantityAtPrice());
}

string TradeSummary::GetCommaSeparatedTradeSummary() const{
    //<symbol>,<MaxTimeGap>,<Volume>,<WeightedAveragePrice>,<MaxPrice>
    return symbol_ + "," + to_string(max_time_gap_) + "," + to_string(volume_)  + "," +
        to_string(weighted_average_price_.GetWeightedAveragePrice()) + "," + to_string(max_price_);
}

} //namespace tradesummarizer