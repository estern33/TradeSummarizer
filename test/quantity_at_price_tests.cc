#include <stdexcept>
#include "gtest/gtest.h"
#include "quantity_at_price.h"

using namespace std;

namespace {

TEST(QuantityAtPrice, NegativeParametersThrow) {
    EXPECT_THROW(tradesummarizer::QuantityAtPrice(-1, -1),invalid_argument);
    EXPECT_THROW(tradesummarizer::QuantityAtPrice(-1, 1),invalid_argument);
    EXPECT_THROW(tradesummarizer::QuantityAtPrice(1, -1),invalid_argument);
}

TEST(QuantityAtPrice, ZeroParametersThrow) {
    EXPECT_THROW(tradesummarizer::QuantityAtPrice(0, 0),invalid_argument);
    EXPECT_THROW(tradesummarizer::QuantityAtPrice(0, 1),invalid_argument);
    EXPECT_THROW(tradesummarizer::QuantityAtPrice(1, 0),invalid_argument);
}

TEST(QuantityAtPrice, PositiveParametersWork) {
    auto test_quantity_at_price = tradesummarizer::QuantityAtPrice(7, 3);
    EXPECT_EQ(test_quantity_at_price.GetQuantity(), 7);
    EXPECT_EQ(test_quantity_at_price.GetPrice(), 3);
}

}  // namespace