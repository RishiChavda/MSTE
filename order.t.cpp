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