#include "order.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(Constructor, ValidInput) {
    
    int orderId=0;
    std::string instruments[]{"VOD.L","HSBA.L"};
    int sizes[]{1763,2024};
    double benchmarkPrices[]{1.23,2.76};  
    
    Order::Direction direction;
  
    int instIndex=orderId%2;
    
    Order newOrder( instruments[0], Order::Buy, sizes[0], benchmarkPrices[0] );
	
    EXPECT_EQ("{ Order symbol 'VOD.L' direction 'B' quantity '1763' limit price '1.23' }", newOrder.toString());
}

TEST(Constructor, AlternateValidInput) {
    
    int orderId=0;
    std::string instruments[]{"VOD.L","HSBA.L"};
    int sizes[]{1763,2024};
    double benchmarkPrices[]{1.23,2.76};  
    
    Order::Direction direction;
  
    int instIndex=orderId%2;
    
    Order newOrder( "BT.A", Order::Sell, 300, 54.67 );
	
    EXPECT_EQ("{ Order symbol 'BT.A' direction 'S' quantity '300' limit price '54.67' }", newOrder.toString());
}