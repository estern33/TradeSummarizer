#ifndef TRADESUMMARIZER_TRADE_INFO_H
#define TRADESUMMARIZER_TRADE_INFO_H

#include <string>

namespace tradesummarizer {

class trade_info {
public:
    trade_info ParseTradeInfoString(std::string trade_string);
};

} //namespace tradesummarizer

#endif //TRADESUMMARIZER_TRADE_INFO_H
