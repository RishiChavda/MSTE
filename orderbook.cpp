#include "orderbook.h"
#include "orderqueue.h"

OrderBook::OrderBook(OrderQueue buys, OrderQueue sells) :
    buyOrders_(buys), sellOrders_(sells) {}


void OrderBook::addOrder(int client, Order& order)
{
    if(order.isBuy()) {
        buyOrders_.insert(order);
    }
    else {
        sellOrders_.insert(order);
    }
}

