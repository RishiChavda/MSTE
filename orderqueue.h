#ifndef OrderQueue_h_
#define OrderQueue_h_

#include "order.h"
#include <vector>
#include <algorithm>

class OrderQueue {
  private:
    std::vector<Order> orders_;
  public:
    OrderQueue() = default;
    void sort();
    void add();
    Order getHighestPriority();
    void removeHighestPriority();
};

#endif // OrderQueue_h_
