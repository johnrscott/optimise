DLIB_PATH = ../../dlib
CFLAGS = -I$(DLIB_PATH)
LDFLAGS =  -lpthread -lX11

all: source.o
	g++ $(CFLAGS) source.o dlib-test.cpp -o test

# I'm not really sure the role of this file, but it seems necessary
# The X11 library needs to be installed with
# sudo apt-get install libx11-dev
source.o:
	g++ -c $(CFLAGS) $(DLIB_PATH)/dlib/all/source.cpp -o source.o $(LDFLAGS)
