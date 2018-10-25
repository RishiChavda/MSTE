#ifndef OrderQueue_h_
#define OrderQueue_h_

#include "order.h"
#include <vector>
#include <ostream>

class OrderQueue {
  private:
    std::vector<Order> orders_;
    size_t size;
  public:
    OrderQueue();
        // Initialize a new object
    
    void insert(Order ord);
        // Adds the specified 'ord' to the queue

    std::ostream& print(std::ostream &out);
        // Prints each order
    
    Order getHighestPriority();
        // Returns the highest priority 'Order' object
    
    void removeHighestPriority();
        // Removes the highest priority 'Order' object
};

#endif // OrderQueue_h_
