#include "match.h"
#include "order.h"
#include <gtest/gtest.h>

TEST(Constructor, CheckBuy) {
    Order buy( "BT.A", Order::Buy, 300, 54.67, 1 );
    Order sell( "BT.A", Order::Sell, 300, 54.67, 1 );

    Match match(buy, sell);
    
    EXPECT_EQ(buy, match.getBuy());
}

TEST(Constructor, CheckSell) {
    Order buy( "BT.A", Order::Buy, 300, 54.67, 1 );
    Order sell( "BT.A", Order::Sell, 300, 54.67, 1 );

    Match match(buy, sell);
    
    EXPECT_EQ(sell, match.getSell());
}