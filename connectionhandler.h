#ifndef ConnectionHandler_h_
#define ConnectionHandler_h_

#include "client.h"
#include <thread>
#include <deque>
#include <string>
#include <mutex>
#include <map>

class ConnectionHandler {
private:
	std::deque< std::string > queue_;
	std::thread thread_;
	bool quitReceived_;
	std::mutex mutex_;
	std::string userIdentifiedAs_;
    std::map<int, Client> serverClients;
private:
	void processMessages();
        // Process network messages and handles them to perform different actions
        // A quit message disconnects the sender
        // A hello message creates a client object and stores the client id
        // A new order message adds the order to the order book
public:
	void start();
	void queueMessage( const char* buffer, size_t length );
        // adds an incoming message to the message queue
    
    bool quitReceived() const;
        // returns quitReceived
        
    void join();
};

inline
bool ConnectionHandler::quitReceived() const {
    return quitReceived_;
}
    
#endif // ConnectionHandler_h_