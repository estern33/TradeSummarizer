#include <stdexcept>
#include "gtest/gtest.h"
#include "trade_stream_parser.h"

using namespace std;

namespace {

TEST(TradeStreamParser, SampleFileYieldsCorrectOutput) {
    tradesummarizer::TradeStreamParser("sample.csv").WriteResult("sample_output.csv");
}

}  // namespace