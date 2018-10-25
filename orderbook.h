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
    void addOrder(int client, Order& order);

    /**
     * Look for matches, execute the matches, and return the fills
     */
    Match findAndExecuteMatches();
};

std::istream& operator>>( std::istream&, Order& );

#endif // OrderBook_h_

