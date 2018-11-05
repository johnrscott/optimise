LDFLAGS =  -L/usr/local/lib/ -lnlopt
CFLAGS = -I../

all:
	g++ nlopt-test.cpp -o test $(LDLIBS)
