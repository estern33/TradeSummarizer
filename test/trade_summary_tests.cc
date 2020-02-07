#include <stdexcept>
#include "gtest/gtest.h"
#include "trade_info.h"
#include "trade_summary.h"

using namespace std;

namespace {

TEST(TradeSummary, SingleTradeHasZeroTimegapAndCorrectVwap) {
    tradesummarizer::TradeSummary trade_summary(tradesummarizer::TradeInfo::ParseTradeInfo("34352,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 0);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
}

TEST(TradeSummary, TimestampsGoingBackwardsThrows) {
    tradesummarizer::TradeSummary trade_summary(tradesummarizer::TradeInfo::ParseTradeInfo("34352,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 0);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
    EXPECT_THROW(trade_summary.UpdateTradeSummary(tradesummarizer::TradeInfo::ParseTradeInfo("1,AAA,4,5")), invalid_argument);
}

TEST(TradeSummary, MultipleTradesCalculateMaxTimeGap) {
    tradesummarizer::TradeSummary trade_summary(tradesummarizer::TradeInfo::ParseTradeInfo("0,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 0);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
    trade_summary.UpdateTradeSummary(tradesummarizer::TradeInfo::ParseTradeInfo("1,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 1);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
    trade_summary.UpdateTradeSummary(tradesummarizer::TradeInfo::ParseTradeInfo("1,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 1);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
    trade_summary.UpdateTradeSummary(tradesummarizer::TradeInfo::ParseTradeInfo("3,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 2);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
}

TEST(TradeSummary, MultipleTradesCalculateMetricsAndBuildString) {
    tradesummarizer::TradeSummary trade_summary(tradesummarizer::TradeInfo::ParseTradeInfo("3432343,AAA,4,5"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 0);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 5);
    trade_summary.UpdateTradeSummary(tradesummarizer::TradeInfo::ParseTradeInfo("35554544444,AAA,12,10"));
    EXPECT_EQ(trade_summary.GetMaxTimeGap(), 35551112101);
    EXPECT_EQ(trade_summary.GetWeightedAveragePrice(), 8);

    EXPECT_EQ(trade_summary.GetVolume(), 16);
    EXPECT_EQ(trade_summary.GetMaxPrice(), 10);

    EXPECT_EQ(trade_summary.GetCommaSeparatedTradeSummary(), "AAA,35551112101,16,8,10");
}

}  // namespace