#include "orderqueue.h"
#include "order.h"

void OrderQueue::sort() {
    
}

Order OrderQueue::getHighestPriority() {
    return orders_[0];
}