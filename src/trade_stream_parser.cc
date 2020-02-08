#include <fstream>
#include <iostream>
#include <stdexcept>
#include <experimental/filesystem>
#include "trade_stream_parser.h"
#include "trade_info.h"

using namespace std;

namespace tradesummarizer {

TradeStreamParser::TradeStreamParser(string input_file_path) {
    if (!experimental::filesystem::exists(input_file_path))
        throw runtime_error("No input file found at " + input_file_path);
    ifstream input_file(input_file_path);
    string line;
    while (getline(input_file, line)) {
        auto trade_info = TradeInfo::ParseTradeInfo(line);
        auto trade_summary_result = trade_summary_per_symbol_.emplace(trade_info.GetSymbol(), TradeSummary(trade_info));

        // if the emplace operation returned an existing trade summary, update it with this trade
        if (!trade_summary_result.second)
            (*trade_summary_result.first).second.UpdateTradeSummary(trade_info);
    }

    if (!input_file.eof())
        throw runtime_error("Stopped reading input file, but did not reach end!");
}

void TradeStreamParser::WriteResult(string output_file_path) {
    ofstream output_file;
    output_file.open(output_file_path);

    for (const auto &[symbol, trade_summary]: trade_summary_per_symbol_) {
        output_file << trade_summary.GetCommaSeparatedTradeSummary() << endl;
    }

    output_file.close();
}

} //namespace tradesummarizer