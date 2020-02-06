#include "weighted_average_price.h"

namespace tradesummarizer {

    void WeightedAveragePrice::AddTrade(const QuantityAtPrice &trade) {
        price_times_volume_ += trade.Price * trade.Quantity;
        total_volume_ += trade.Quantity;
    }

    long WeightedAveragePrice::GetWeightedAveragePrice() {
        if (total_volume_ == 0)
            return 0;

        // Per instructions, price should be truncated to whole numbers, not rounded.
        return price_times_volume_ / total_volume_;
    }
} //namespace tradesummarizer
