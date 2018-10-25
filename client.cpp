#include "client.h"

Client::Client(int clientId) : clientId_(clientId) {
    
}

Client::Client( const Client& client) : clientId_(client.clientId_) {
    for(int i = 0; i < orders_.size(); i++) {
        orders_[i] = client.orders_[i];
    }
}

Order Client::addOrder(Order& order) {
    return order;
}