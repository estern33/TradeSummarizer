#include "weighted_average_price.h"

namespace tradesummarizer {

    void WeightedAveragePrice::AddTrade(const QuantityAtPrice &trade) {
        price_times_volume_ += trade.GetPrice() * trade.GetQuantity();
        total_volume_ += trade.GetQuantity();
    }

    unsigned long WeightedAveragePrice::GetWeightedAveragePrice() const {
        if (total_volume_ == 0)
            return 0;

        // Per instructions, price should be truncated to whole numbers, not rounded.
        return price_times_volume_ / total_volume_;
    }
} //namespace tradesummarizer
