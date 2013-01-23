CC=gcc
CXX=g++
#CFLAGS= -g `sdl-config --cflags --libs` -lSDL -lSDL_image -lglut -lGL -lGLU 
CCFLAGS= -g -Wall 
LIBS= -lSDL -lSDL_image -lglut -lGL -lGLU
INC=-I.

DEPS = NWTypes.h

OBJS = main.o \
	NWImage_SDL.o \
	NWTexture2D.o

%.o: %.c $(DEPS)
	$(CXX) $(CCFLAGS) $(INC) -c $@ -o $<

HTW: $(OBJS)
	$(CXX) $(CCFLAGS) $(OBJS) -o $@ $(LIBS)

.PHONY:clean
clean:
	rm *.o HTW
