//
// Created by Evan on 2/5/2020.
//

#include <stdexcept>

#include "gtest/gtest.h"

#include "quantity_at_price.h"

using namespace std;
using namespace tradesummarizer;

namespace {

TEST(QuantityAtPrice, NegativeParametersThrow) {
    EXPECT_THROW(QuantityAtPrice test_qty(-1, -1),invalid_argument);
    EXPECT_THROW(QuantityAtPrice test_qty(-1, 1),invalid_argument);
    EXPECT_THROW(QuantityAtPrice test_qty(1, -1),invalid_argument);
}

TEST(QuantityAtPrice, ZeroParametersThrow) {
    EXPECT_THROW(QuantityAtPrice test_qty(0, 0),invalid_argument);
    EXPECT_THROW(QuantityAtPrice test_qty(0, 1),invalid_argument);
    EXPECT_THROW(QuantityAtPrice test_qty(1, 0),invalid_argument);
}

TEST(QuantityAtPrice, PositiveParametersWork) {
    QuantityAtPrice test_qty(7, 3);
    EXPECT_EQ(test_qty.Quantity, 7);
    EXPECT_EQ(test_qty.Quantity, 7);
}

}  // namespace