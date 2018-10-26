#ifndef OrderBook_h_
#define OrderBook_h_

#include "order.h"
#include "orderqueue.h"
#include "match.h"
#include <string>

class OrderBook {
private:
    OrderQueue buyOrders_;
    OrderQueue sellOrders_;
public:
    OrderBook() = default;
    
    OrderBook(OrderQueue buys, OrderQueue sells);
        // Constructs and orderbook object with a specified 'buy' queue and 'sell' queue
        
    void addOrder(int client, Order& order);
        // Adds an order to either the buy or sell queue based on the order type

    OrderQueue getBuys();
    
    OrderQueue getSells();

    Match findAndExecuteMatches();
        // Searches for orders than can create a trade, performs a trade 
        // on the objects and returns the remaining match
};

inline
OrderQueue OrderBook::getBuys() {
    return buyOrders_;
}

inline
OrderQueue OrderBook::getSells() {
    return sellOrders_;
}

std::istream& operator>>( std::istream&, Order& );

#endif // OrderBook_h_

