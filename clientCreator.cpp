#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "order.h"
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using boost::asio::ip::tcp;

int orderId=0;
std::string instruments[]{"VOD.L","HSBA.L"};
int sizes[]{1763,2024};
double benchmarkPrices[]{1.23,2.76}; //TODO change all floats to doubles

double randomDoubleWithinRange(double min, double max) {
    srand(time(NULL));   
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

int randomIntWithinRange(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

void sendNewOrder( tcp::socket& socket, int clientid ) {
	boost::system::error_code ignored_error;
	int size = randomIntWithinRange(sizes[0], sizes[1]);
    double price = roundf(randomDoubleWithinRange(benchmarkPrices[0], benchmarkPrices[1]) * 100) / 100;
    int instrumentIndex = randomIntWithinRange(0, 1);
    bool isBuy = randomIntWithinRange(0, 1);
    Order::Direction direction;
    if(isBuy) {
        direction = Order::Buy;
    }
    else {
        direction = Order::Sell;
    }
    //TODO change from modulo to random
	Order newOrder(instruments[instrumentIndex], direction, size, price, clientid); //TODO make the numbers random
	std::cout<<"Sending order "<<orderId++<<" "<<newOrder.toString()<<"\n";
	//TASK change the protocol to include the order id
	//TASK change the protocol to FIX
	boost::asio::write(socket, boost::asio::buffer("NEW_ORDER" + newOrder.serialise()), ignored_error);
}

int main(int argc, char* argv[]){
	try{
		if (argc != 4){
			std::cerr << "Usage: " << argv[0] << " <host> <port> <clientid>\n";
			return 1;
		}

		boost::asio::io_service io_service;

		tcp::resolver resolver(io_service);
		std::string port( argv[2] );
		tcp::resolver::query query(argv[1], port );
		std::string clientid(argv[3]);
        
        for(int i = 0; i < clientid.size(); i++) {
            if( isdigit(clientid[i]) == 0) {
                std::cout << "This id must only contain numbers\n";
                return 0;
            }
        }
        
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

		tcp::socket socket(io_service);
		std::cout<<"Connecting to server: "<<argv[1]<<":"<<port<<"\n";
		boost::asio::connect(socket, endpoint_iterator);

		{
			std::string message = "HELLO_I_AM " + clientid;
			boost::system::error_code ignored_error; //TASK don't ignore errors
			std::cout<<"Logging in\n";
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
		std::cout<<"sleep 5\n";
		sleep(5);
		int numOrders=10+rand()%100;
		for (int i = 0; i < numOrders; ++i) { //TASK have the server respond to the client with fill messages
			sendNewOrder( socket, std::stoi(clientid) );
			sleep(10); //TASK make random between 0.1s and 3s
		}
		std::cout<<"Logging out\n";
		{
		std::string message = "QUIT ";
			boost::system::error_code ignored_error;
		boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}

//		for (;;)
//		{
//			boost::array<char, 128> buf;
//			boost::system::error_code error;
//
//			size_t len = socket.read_some(boost::asio::buffer(buf), error);
//
//			if (error == boost::asio::error::eof)
//				break; // Connection closed cleanly by peer.
//			else if (error)
//				throw boost::system::system_error(error); // Some other error.
//
//			std::cout.write(buf.data(), len);
//		}
	}catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
