ALL: server client orderbook order

OBJECTS = orderbook.o order.o matches.o orderqueue.o clienthandler.o orderbook.t.o order.t.o
INCLUDE_DIRS = -I. -I/home/ibutt/googletest-master/googletest/include
GTESTMAIN = /home/ibutt/googletest-master/googletest/make/gtest_main.a
CPP11=-std=c++11
COMPILE_FOR_DEBUG=-Og -g
LIBRARIES= \
/usr/lib64/libboost_system-mt.so.1.53.0

CPPFLAGSWITHGTEST=$(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) $(GTESTMAIN)

clean:
	-rm -f server client orderbook order *.o *.gch

connectionhandler.o: connectionhandler.cpp connectionhandler.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^

order.o: order.cpp order.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^

orderbook.o: orderbook.cpp orderbook.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^
	
matches.o: matches.cpp matches.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^

orderqueue.o: orderqueue.cpp orderqueue.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -c $^
	
orderbook.t.o: orderbook.t.cpp orderbook.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^	
	
order.t.o: order.t.cpp order.h
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) $(INCLUDE_DIRS) -c $^

server: server.cpp connectionhandler.o order.o orderbook.o matches.o orderqueue.o
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -o $@ server.cpp order.o orderbook.o connectionhandler.o matches.o orderqueue.o $(LIBRARIES) -lpthread

client: client.cpp order.o
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -o $@ $^ $(LIBRARIES) -lpthread
	
orderbook: orderbook.t.o
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread
	
order: order.t.o
	g++ $(CPP11) $(COMPILE_FOR_DEBUG) -o $@ $^ $(GTESTMAIN) $(LIBRARIES) -lpthread