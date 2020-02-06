//
// Created by Evan on 2/4/2020.
//

#ifndef TRADESUMMARIZER_QUANTITY_AT_PRICE_H
#define TRADESUMMARIZER_QUANTITY_AT_PRICE_H

namespace tradesummarizer {

// Immutable representation of a price and quantity pair.
class QuantityAtPrice {
public:
    QuantityAtPrice(int quantity, int price);

    // QuantityAtPrice is immutable, disable default copy constructor.
    QuantityAtPrice(QuantityAtPrice const &) = delete;

    // QuantityAtPrice is immutable, disable default copy assignment operator.
    QuantityAtPrice &operator=(const QuantityAtPrice &) = delete;

    // Assuming quantity, like price, is no larger than int and a whole number.
    const int Quantity;
    //From instructions.txt SafeAssumptions, Price - our currency is an integer based currency.  No decimal points.  Price - Price is always > 0.
    const int Price;
};

} //namespace tradesummarizer


#endif //TRADESUMMARIZER_QUANTITY_AT_PRICE_H
