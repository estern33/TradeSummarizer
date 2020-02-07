#include <stdexcept>
#include "gtest/gtest.h"
#include "trade_info.h"

using namespace std;

namespace {

TEST(TradeInfo, EmptyAndBadStringsThrow) {
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo(""), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("123,a,1"), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("a,a,a,a"), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("123,aaa,123,123,123"), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("123,123,123,123"), invalid_argument);
}

TEST(TradeInfo, WellFormedStringWithBadDataThrow) {
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("-123,AAA,3,2"), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("123,AAA,-1,4"), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("123,AAA,1,-4"), invalid_argument);
    EXPECT_THROW(tradesummarizer::TradeInfo::ParseTradeInfo("86400000001,AAA,1,4"), invalid_argument);
}

TEST(TradeInfo, GoodStringsWork)
{
    auto trade_info = tradesummarizer::TradeInfo::ParseTradeInfo("52924702,aaa,13,1136");
    EXPECT_EQ(trade_info.GetTimestamp(), 52924702);
    EXPECT_EQ(trade_info.GetSymbol(), "aaa");
    EXPECT_EQ(trade_info.GetQuantityAtPrice().GetQuantity(), 13);
    EXPECT_EQ(trade_info.GetQuantityAtPrice().GetPrice(), 1136);

    trade_info = tradesummarizer::TradeInfo::ParseTradeInfo("2342,ABC,433,4988");
    EXPECT_EQ(trade_info.GetTimestamp(), 2342);
    EXPECT_EQ(trade_info.GetSymbol(), "ABC");
    EXPECT_EQ(trade_info.GetQuantityAtPrice().GetQuantity(), 433);
    EXPECT_EQ(trade_info.GetQuantityAtPrice().GetPrice(), 4988);
}

}  // namespace