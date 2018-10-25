#include "order.h"
#include "orderqueue.h"
#include "orderbook.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(OrderQueue, CreationAndInsertion) {
    OrderQueue oq1;
    
    Order o1("VOD.L", Order::Direction::Buy, 500, 230.81, 1);
    oq1.insert(o1);
    
    std::cout << "\n" << oq1.getHighestPriority().toString() << "\n";
    
    
    Order o2("BT.A", Order::Direction::Buy, 500, 30.81, 2);
    oq1.insert(o2);
    
    std::cout << "\n" << oq1.getHighestPriority().toString() << "\n";
    oq1.removeHighestPriority();
    std::cout << "\n" << oq1.getHighestPriority().toString() << "\n";
    
    
    
}