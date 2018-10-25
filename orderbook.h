#ifndef OrderBook_h_
#define OrderBook_h_

#include <thread>
#include <deque>
#include <string>
#include <mutex>
#include "order.h"
#include "orderqueue.h"
#include "match.h"

class OrderBook {
private:
    OrderQueue buyOrders_;
    OrderQueue sellOrders_;
public:
    void addOrder(const std::string& client, const Order& order);

    /**
     * Look for matches, execute the matches, and return the fills
     */
    Match findAndExecuteMatches();
};

std::istream& operator>>( std::istream&, Order& );

#endif // OrderBook_h_

