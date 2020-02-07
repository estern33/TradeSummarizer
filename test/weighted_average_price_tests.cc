#include <stdexcept>
#include "gtest/gtest.h"
#include "weighted_average_price.h"

namespace {

TEST(WeightedAveragePrice, NoTradesAddedReturnsZero) {
    tradesummarizer::WeightedAveragePrice vwap;
    EXPECT_EQ(0, vwap.GetWeightedAveragePrice());
}

TEST(WeightedAveragePrice, VwapIsCorrectForTrades) {
    //	20 shares of aaa @ 18
    //	5 shares of aaa @ 7
    //	Weighted Average Price = ((20 * 18) + (5 * 7)) / (20 + 5) = 15

    tradesummarizer::WeightedAveragePrice vwap;
    vwap.AddTrade(tradesummarizer::QuantityAtPrice(20, 18));
    EXPECT_EQ(18, vwap.GetWeightedAveragePrice());
    vwap.AddTrade(tradesummarizer::QuantityAtPrice(5, 7));
    EXPECT_EQ(15, vwap.GetWeightedAveragePrice());
}

}  // namespace