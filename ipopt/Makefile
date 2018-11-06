CFLAGS = -std=c++11 -I../../Ipopt/include/coin
LDFLAGS =  -L../../Ipopt/lib -lipopt

# I needed to run ldconfig after installing liboptim

all:
	g++ $(CFLAGS) ipopt-test.cpp -o test $(LDFLAGS)

clean:
	rm test
