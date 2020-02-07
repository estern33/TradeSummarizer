#include <stdexcept>
#include "quantity_at_price.h"

using namespace std;

namespace tradesummarizer {

QuantityAtPrice::QuantityAtPrice(int quantity, int price) {
    if (quantity <= 0)
        throw invalid_argument("Quantity given to QuantityAtPrice constructor must be greater than zero.  Was " + to_string(quantity) + ".");
    if (price <= 0)
        throw invalid_argument("Price given to QuantityAtPrice constructor must be greater than zero.  Was " + to_string(price) + ".");

    quantity_ = quantity;
    price_ = price;
}

} //namespace tradesummarizer