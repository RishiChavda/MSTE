#ifndef Match_h_
#define Match_h_

#include "order.h"

class Match {
  private:
    Order buy_;
    Order sell_;
  public:
    Match(Order buy, Order sell);
        // Constructs the buy and sell order queues

    Order getBuy();
        // Returns the buy queue
        
    Order getSell();
        // Returns the sell queue
};

inline
Order Match::getBuy() {
    return buy_;
}

inline
Order Match::getSell() {
    return sell_;
}

#endif // Match_h_