#include "orderqueue.h"
#include "order.h"
#include <algorithm>
#include <ostream>

OrderQueue::OrderQueue() {
    size = 10;
    orders_.reserve(10);
    orders_.resize(10);
}

void OrderQueue::insert(Order ord) {
    orders_.resize(2);
    for(size_t i = 0; i < orders_.size(); ++i) {
        if (ord > orders_[i]) {
            Order temp;
            temp = orders_[i];
            orders_[i] = ord;
            ord = temp;
        }
    }
    orders_.push_back(ord);
}

std::ostream& OrderQueue::print(std::ostream &out) {
    for(size_t i = 0; i<orders_.size(); ++i) {
        out << orders_[i].toString();
    }
    return out;
}

Order OrderQueue::getHighestPriority() {
    return orders_[0];
}

void OrderQueue::removeHighestPriority() {
    orders_.erase(orders_.begin());
    /*
    for(size_t i=0; i<orders_.size(); ++i) {
        orders_[i] = orders_[i+1];
    }
    */
}

