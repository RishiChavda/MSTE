#include "order.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(Constructor, correctInitialisation) {
    
    int orderId=0;
    std::string instruments[]{"VOD.L","HSBA.L"};
    int sizes[]{1763,2024};
    double benchmarkPrices[]{1.23,2.76};  
    
    Order::Direction direction;
  
    int instIndex=orderId%2;
    
    Order newOrder( instruments[0], Order::Buy, sizes[0], benchmarkPrices[0] );
	
    EXPECT_EQ("{ Order symbol 'VOD.L' direction 'B' quantity '1763' limit price '1.23' }", newOrder.toString());
}
