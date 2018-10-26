#include <gtest/gtest.h>
#include <stdexcept>
#include "orderbook.h"
#include "orderqueue.h"

TEST (Constructor, ValidInput) {
    OrderQueue buy;
    OrderQueue sell;
    
    Order newOrder1( "BT.A", Order::Buy, 300, 54.67, 1 );
    Order newOrder2( "BT.A", Order::Sell, 300, 54.67, 1 );
    
    buy.insert(newOrder1);
    sell.insert(newOrder2);
    
    OrderBook book(buy, sell);
	
    // TODO: FIND A WAY TO TEST THIS
}

//TODO Complete the below tests

TEST (AddingOrdersToBuy, ValidInput) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
    
    OrderBook book();
    book.addOrder(newOrder);
}

TEST (AddingOrdersToBuy, ZeroInput) {
    Order newOrder( "BT.A", Order::Buy, 300, 0.0, 1 );
    
    OrderBook book();
    book.addOrder(newOrder);
}

TEST (AddingOrdersToBuy, NegativeInput) {
    Order newOrder( "BT.A", Order::Buy, 300, -54.67, 1 );
    
    OrderBook book();
    book.addOrder(newOrder);
}

TEST (AddingOrdersToSell, ValidInput) {
    Order newOrder( "BT.A", Order::Sell, 300, 54.67, 1 );
    
    OrderBook book();
    book.addOrder(newOrder);
}

TEST (AddingOrdersToSell, ZeroInput) {
    Order newOrder( "BT.A", Order::Sell, 300, 0.0, 1 );
    
    OrderBook book();
    book.addOrder(newOrder);
}

TEST (AddingOrdersToSell, NegativeInput) {
    Order newOrder( "BT.A", Order::Sell, 300, -54.67, 1 );
    
    OrderBook book();
    book.addOrder(newOrder);
}


