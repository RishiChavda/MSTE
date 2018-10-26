#include "client.h"
#include <iostream> 
Client::Client(int clientId) : clientId_(clientId) {
    
}

Client::Client( const Client& client) : clientId_(client.clientId_) {
    for(int i = 0; i < orders_.size(); i++) {
        orders_[i] = client.orders_[i];
    }
}

void Client::addOrder(Order& order) {
    orders_.push_back(order);
}

bool Client::searchForOrder(Order order) {
    for(int i = 0; i < orders_.size(); i++) {        
        if(orders_[i] == order) {
            return true;
        }
    }
    
    return false;
}