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
            // Constructs a client object with a specified 'clientId'
            
        Client( const Client& client);
            // Constructs a client object from a specified 'client'
            
        Order addOrder(Order& order);
            // Adds an order to the client's orders used as reference for the client
};

#endif // __CLIENT__