#include "order.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(Constructor, ValidInputBuy) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
	
    EXPECT_EQ("{ Order symbol 'BT.A' direction 'B' quantity '300' limit price '54.67' client id '1' }", newOrder.toString());
}

TEST(Constructor, ValidInputSell) {
    Order newOrder( "BT.A", Order::Sell, 300, 54.67, 1 );
	
    EXPECT_EQ("{ Order symbol 'BT.A' direction 'S' quantity '300' limit price '54.67' client id '1' }", newOrder.toString());
}

TEST(Serialise, ValidInputBuy) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
	
    EXPECT_EQ("BT.A B 300 54.67 1", newOrder.serialise());
}

TEST(Serialise, ValidInputSell) {
    Order newOrder( "BT.A", Order::Sell, 300, 54.67, 1 );
	
    EXPECT_EQ("BT.A S 300 54.67 1", newOrder.serialise());
}

TEST(IsBuy, ValidReturnBuy) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
	
    EXPECT_EQ(true, newOrder.isBuy());
}

TEST(IsBuy, ValidReturnSell) {
    Order newOrder( "BT.A", Order::Sell, 300, 54.67, 1 );
	
    EXPECT_EQ(false, newOrder.isBuy());
}

TEST(ClientId, ValidValue) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
	
    EXPECT_EQ(1, newOrder.clientId());
}

TEST(ClientId, ZeroValue) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 0 );
	
    EXPECT_EQ(0, newOrder.clientId());
}

TEST(ClientId, NegativeValue) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, -1 );
	
    EXPECT_EQ(-1, newOrder.clientId());
}

TEST(LimitPrice, ValidValue) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
	
    EXPECT_EQ(54.67, newOrder.getLimitPrice());
}

TEST(LimitPrice, ZeroValue) {
    Order newOrder( "BT.A", Order::Buy, 300, 0.0, 1 );
	
    EXPECT_EQ(0.0, newOrder.getLimitPrice());
}

TEST(LimitPrice, NegativeValue) {
    Order newOrder( "BT.A", Order::Buy, 300, -54.67, 1 );
	
    EXPECT_EQ(-54.67, newOrder.getLimitPrice());
}