CFLAGS = -I/usr/local/include/optim
LDFLAGS =  -L/usr/local/lib -loptim

# I needed to run ldconfig after installing liboptim

all:
	g++ $(CFLAGS) optimlib-test.cpp -o test $(LDFLAGS)

clean:
	rm test
