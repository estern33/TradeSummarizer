#ifndef TRADESUMMARIZER_QUANTITY_AT_PRICE_H
#define TRADESUMMARIZER_QUANTITY_AT_PRICE_H

namespace tradesummarizer {

// Immutable representation of a price and quantity pair.
class QuantityAtPrice {
public:
    // Returns a QuantityAtPrice instance if quantity and price are both positive, throws otherwise.
    // Was tempted to make these parameters unsigned, but leaving them signed enables defensive checking the file input.
    QuantityAtPrice(int quantity, int price);

    unsigned int GetQuantity() const {return quantity_;}
    unsigned int GetPrice() const {return price_;}

private:
    // Assuming quantity, like price, is no larger than int and a whole number.
    unsigned int quantity_;
    // From instructions.txt SafeAssumptions, Price - our currency is an integer based currency.  No decimal points.  Price - Price is always > 0.
    unsigned int price_;
};

} //namespace tradesummarizer


#endif //TRADESUMMARIZER_QUANTITY_AT_PRICE_H
