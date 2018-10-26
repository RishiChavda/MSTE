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
    
    OrderBook book;
    book.addOrder(1, newOrder);
    
    Order ord = book.getBuys().getHighestPriority();
    
    EXPECT_EQ(ord.getSymbol(), "BT.A");
    EXPECT_EQ(ord.getDirection(), Order::Buy);
    EXPECT_EQ(ord.getQuantity(), 300);
    EXPECT_EQ(ord.getLimitPrice(), 54.67);
    EXPECT_EQ(ord.clientId(), 1);

}

TEST (AddingOrdersToBuy, ZeroInput) {
    Order newOrder( "BT.A", Order::Buy, 300, 0.0, 1 );
    
    OrderBook book;
    book.addOrder(1, newOrder);
}

TEST (AddingOrdersToBuy, NegativeInput) {
    Order newOrder( "BT.A", Order::Buy, 300, -54.67, 1 );
    
    OrderBook book;
    book.addOrder(1, newOrder);
}

TEST (AddingOrdersToSell, ValidInput) {
    Order newOrder( "BT.A", Order::Sell, 300, 54.67, 1 );
    
    OrderBook book;
    book.addOrder(1, newOrder);
}

TEST (AddingOrdersToSell, ZeroInput) {
    Order newOrder( "BT.A", Order::Sell, 300, 0.0, 1 );
    
    OrderBook book;
    book.addOrder(1, newOrder);
}

TEST (AddingOrdersToSell, NegativeInput) {
    Order newOrder( "BT.A", Order::Sell, 300, -54.67, 1 );
    
    OrderBook book;
    book.addOrder(1, newOrder);
}


