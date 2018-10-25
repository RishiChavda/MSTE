#ifndef __CLIENT__
#define __CLIENT__

#include <vector>
#include "order.h"

class Client {
    
    private:
        int clientId_;
        std::vector<Order> orders_;
        
    public:
        Client(int clientId);
        Client( const Client& client);
        Order addOrder(Order& order);

};

#endif // __CLIENT__