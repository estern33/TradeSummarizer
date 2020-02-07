#include <fstream>
#include <iostream>
#include "trade_stream_parser.h"

using namespace std;

namespace tradesummarizer {

TradeStreamParser::TradeStreamParser(string input_file_path) {
    ifstream input_file;
    string line;
    while (getline(input_file, line)) {
        cout << line << endl;
//        if (trade_summary_per_symbol_.find(trade_info.line))
//            trade_summary_per_symbol.
    }
}

void WriteResult(string output_file_path) {

}

} //namespace tradesummarizer