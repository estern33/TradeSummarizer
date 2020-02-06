#include <stdexcept>

#include "gtest/gtest.h"

#include "weighted_average_price.h"

using namespace tradesummarizer;

namespace {

TEST(WeightedAveragePrice, NoTradesAddedReturnsZero) {
    WeightedAveragePrice vwap;
    EXPECT_EQ(0, vwap.GetWeightedAveragePrice());
}

TEST(WeightedAveragePrice, VwapIsCorrectForTrades) {
    //	20 shares of aaa @ 18
    //	5 shares of aaa @ 7
    //	Weighted Average Price = ((20 * 18) + (5 * 7)) / (20 + 5) = 15

    WeightedAveragePrice vwap;
    vwap.AddTrade(QuantityAtPrice(20, 18));
    EXPECT_EQ(18, vwap.GetWeightedAveragePrice());
    vwap.AddTrade(QuantityAtPrice(5, 7));
    EXPECT_EQ(15, vwap.GetWeightedAveragePrice());
}

}  // namespace