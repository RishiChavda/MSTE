#include "client.h"
#include "order.h"
#include <gtest/gtest.h>

TEST(OrderSearching, FindingOrder) {
    Order newOrder( "BT.A", Order::Buy, 300, 54.67, 1 );
    
    Client client(1);
    
    client.addOrder(newOrder);
    
    EXPECT_TRUE(client.searchForOrder(newOrder));
}

TEST(OrderSearching, NoOrderFound) {
    Order newOrder1( "BT.A", Order::Buy, 300, 54.67, 1 );
    Order newOrder2( "BT.A", Order::Sell, 300, 54.67, 1 );

    Client client(1);
    
    client.addOrder(newOrder1);
    
    EXPECT_FALSE(client.searchForOrder(newOrder2));
}