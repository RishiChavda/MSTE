#include <gtest/gtest.h>
#include <stdexcept>
#include "orderbook.h"
#include "orderqueue.h"

TEST (Constructor, ValidInput)
{
    OrderQueue buy;
    OrderQueue sell;
    
    Order newOrder1( "BT.A", Order::Buy, 300, 54.67, 1 );
    Order newOrder2( "BT.A", Order::Sell, 300, 54.67, 1 );
    
    buy.insert(newOrder1);
    sell.insert(newOrder2);
    
    OrderBook book(buy, sell);
	
    // TODO: FIND A WAY TO TEST THIS
}

TEST (OrderBookTest, test2)
{
}

TEST (OrderBookTest, test3)
{
}


