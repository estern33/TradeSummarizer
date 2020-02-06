//
// Created by Evan on 2/4/2020.
//

#ifndef TRADESUMMARIZER_WEIGHTED_AVERAGE_PRICE_H
#define TRADESUMMARIZER_WEIGHTED_AVERAGE_PRICE_H

#include "quantity_at_price.h"

namespace tradesummarizer {

// Weighted Average Price.  Average price per unit traded not per trade.
//  Result should be truncated to whole numbers.
//
//  Example: the following trades
//	20 shares of aaa @ 18
//	5 shares of aaa @ 7
//	Weighted Average Price = ((20 * 18) + (5 * 7)) / (20 + 5) = 15

class WeightedAveragePrice {
public:
    // Each value to be included in this VWAP should be added via the AddTrade function as a QuantityAtPrice.
    void AddTrade(const QuantityAtPrice &trade);

    // Get the VWAP for all trades recorded from AddTrade.
    // Can be called, have more trades added, then called again for the updated value.
    // Truncated to whole numbers, returns long instead of double accordingly.
    // If no trades were recorded, VWAP will return 0.
    long GetWeightedAveragePrice();

private:
    long price_times_volume_ = 0; // price is assumed to be a positive integer value per the instructions, assuming quantity is the same, hence price times quantity can be a long
    long total_volume_ = 0;
};

} //namespace tradesummarizer

#endif //TRADESUMMARIZER_WEIGHTED_AVERAGE_PRICE_H
