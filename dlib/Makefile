DLIB_PATH = ../../dlib
CFLAGS = -std=c++11 -I$(DLIB_PATH)
LDFLAGS =  -lpthread -lX11

# I got a weird runtime error -- couldn't find a symbol in libstdc++.so.6
# I changed libstdc++.so.6 to point to libstdc++.so.6.0.23 rather than
# libstdc++.so.6.0.24

all: source.o
	g++ $(CFLAGS) source.o dlib-test.cpp -o test $(LDFLAGS)
# I'm not really sure the role of this file, but it seems necessary
# The X11 library needs to be installed with
# sudo apt-get install libx11-dev
source.o:
	g++ -c $(CFLAGS) $(DLIB_PATH)/dlib/all/source.cpp -o source.o

clean:
	rm *.o test
