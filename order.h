#ifndef Order_h_
#define Order_h_


// WHAT'S WRONG HERE???
#include <thread>
#include <deque>
#include <string>
#include <mutex>

class Order {
    friend std::istream& operator>>( std::istream&, Order& );
public:
    enum Direction { Buy = 'B', Sell = 'S' };
private:
    std::string symbol_;
    Direction direction_;
    size_t quantity_;
    double limitPrice_;
    int clientId_;
public:
    Order() = default;

    Order( const std::string& symbol, Direction direction, size_t quantity, double limitPrice, int clientId );
        // Constructs and order object with the specified parameters

    std::string getSymbol();
        // Returns the symbol

    Order::Direction getDirection();
        // Returns the direction of the order (Buy or Sell)

    size_t getQuantity();
        // Returns the order quantity

    double getLimitPrice() const;
        // returns the price of an order
    
    int clientId() const;
        // returns the client id of an order
        
    std::string serialise() const;
        // Converts the symbol, direction, quantity, price 
        // and client id of an order into a single serialised string and returns the string
    
    std::string toString() const;
        // Converts the symbol, direction, quantity, price 
        // and client id of an order into a single string and returns the string 
    
    bool operator> (const Order &o1);
        // compares if a price of this object is greater than the price of the specified '01'
    
    bool isBuy();
        // returns if the order is a buy or sell order
};

std::istream& operator>>( std::istream& is, Order& order );

inline
std::string Order::getSymbol() {
    return symbol_;
}

inline
Order::Direction Order::getDirection() {
    return direction_;
}

inline
size_t Order::getQuantity() {
    return quantity_;
}

inline
double Order::getLimitPrice() const {
    return limitPrice_;
}

inline
bool Order::operator> (const Order &c1) {
    return getLimitPrice() > c1.getLimitPrice();
}


#endif // Order_h_
