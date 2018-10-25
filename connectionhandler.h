#ifndef ConnectionHandler_h_
#define ConnectionHandler_h_

#include <thread>
#include <deque>
#include <string>
#include <mutex>

class ConnectionHandler {
private:
	std::deque< std::string > queue_;
	std::thread thread_;
	bool quitReceived_;
	std::mutex mutex_;
	std::string userIdentifiedAs_;
private:
	void processMessages();
public:
	void start();
	void queueMessage( const char* buffer, size_t length );
        // 
    
    bool quitReceived() const;
        // returns quitReceived
        
    void join();
};

inline
bool ConnectionHandler::quitReceived() const {
    return quitReceived_;
}
    
#endif // ConnectionHandler_h_
