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
    Order( const std::string& symbol, Direction direction, size_t quantity, double limitPrice, int clientId );
    std::string serialise() const;
    Order() = default;
    std::string toString() const;
    int clientId();
};

std::istream& operator>>( std::istream& is, Order& order );

#endif // Order_h_
