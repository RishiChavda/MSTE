#include "orderbook.h"
#include "orderqueue.h"

OrderBook::OrderBook(OrderQueue buys, OrderQueue sells) :
    buyOrders_(buys), sellOrders_(sells) {}


void OrderBook::addOrder(const std::string& client, const Order& order)
{}

