#include <fstream>
#include <iostream>
#include "trade_stream_parser.h"
#include "trade_info.h"

using namespace std;

namespace tradesummarizer {

TradeStreamParser::TradeStreamParser(string input_file_path) {
    ifstream input_file(input_file_path);
    string line;
    while (getline(input_file, line)) {
        auto trade_info = TradeInfo::ParseTradeInfo(line);
        auto trade_summary_result = trade_summary_per_symbol_.emplace(trade_info.GetSymbol(), TradeSummary(trade_info));

        // if the emplace operation returned an existing trade summary, update it with this trade
        if (!trade_summary_result.second)
            (*trade_summary_result.first).second.UpdateTradeSummary(trade_info);
    }
}

void TradeStreamParser::WriteResult(string output_file_path) {
    ofstream output_file;
    output_file.open (output_file_path);

    map<string, TradeSummary>::iterator it;
    for ( it = trade_summary_per_symbol_.begin(); it != trade_summary_per_symbol_.end(); it++ ) {
        output_file << it->second.GetCommaSeparatedTradeSummary() << endl;
    }

    output_file.close();
}

} //namespace tradesummarizer