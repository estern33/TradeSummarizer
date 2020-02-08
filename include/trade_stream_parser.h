#ifndef TRADESUMMARIZER_TRADE_STREAM_PARSER_H
#define TRADESUMMARIZER_TRADE_STREAM_PARSER_H

#include <string>
#include <map>
#include "trade_summary.h"

namespace tradesummarizer {

// Takes an input stream of trade format specified in instructions.txt,
// creates a map of trade summary per symbol encountered in the stream.
// Can write map to output stream in csv format.
class TradeStreamParser {
public:
    TradeStreamParser(std::string input_file_path);

    void WriteResult(std::string output_file_path);

private:
    // Requirements are that output file is ordered by symbol, map seems similar to java tree map in that it sorts by key.
    std::map<std::string, TradeSummary> trade_summary_per_symbol_;
};

} //namespace tradesummarizer

#endif //TRADESUMMARIZER_TRADE_STREAM_PARSER_H
