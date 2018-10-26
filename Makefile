ALL: server client orderbookTest orderTest orderqueueTest clientTest matchTest systemTest

INCLUDE_DIRS = -I. -I/home/ibutt/googletest-master/googletest/include
GTESTMAIN = /home/ibutt/googletest-master/googletest/make/gtest_main.a
CPP11=-std=c++11
COMPILE_FOR_DEBUG=-Og -g
LIBRARIES= \
/usr/lib64/libboost_system-mt.so.1.53.0

CPPFLAGSWITHGTEST=$(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) $(GTESTMAIN)

clean:
	-rm -f server client orderbookTest orderqueueTest orderTest clientTest matchTest systemTest *.o *.gch

connectionhandler.o: connectionhandler.cpp connectionhandler.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^

order.o: order.cpp order.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^

orderbook.o: orderbook.cpp orderbook.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^
	
match.o: match.cpp match.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^

orderqueue.o: orderqueue.cpp orderqueue.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^
	
client.o: client.cpp client.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^
	
orderqueue.t.o: orderqueue.t.cpp orderqueue.h order.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^	
	
order.t.o: order.t.cpp order.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^
	
orderbook.t.o: orderbook.t.cpp orderbook.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^
	
client.t.o: client.t.cpp client.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^
	
match.t.o: match.t.cpp match.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^
	
server: server.cpp connectionhandler.o order.o orderbook.o match.o orderqueue.o client.o
	g++ $(CPP11) -o $@ server.cpp order.o orderbook.o connectionhandler.o match.o orderqueue.o client.o $(LIBRARIES) -lpthread

client: clientCreator.cpp order.o
	g++ $(CPP11) -o $@ clientCreator.cpp order.o $(LIBRARIES) -lpthread
	
orderbookTest: orderbook.t.o orderbook.o orderqueue.o order.o
	g++ $(CPP11) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread
	
orderTest: order.t.o order.o
	g++ $(CPP11) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread

orderqueueTest: orderqueue.t.o orderqueue.o order.o
	g++ $(CPP11) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread
	
clientTest: client.t.o client.o order.o
	g++ $(CPP11) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread
	
matchTest: match.t.o match.o order.o
	g++ $(CPP11) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread
		
systemTest: orderbook.t.o order.t.o client.t.o match.t.o match.o client.o orderbook.o orderqueue.o order.o
	g++ $(CPP11) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread