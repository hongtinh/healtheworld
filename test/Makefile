CC=gcc
CXX=g++
#CFLAGS= -g `sdl-config --cflags --libs` -lSDL -lSDL_image -lglut -lGL -lGLU 
CCFLAGS= -g -Wall 
LIBS= -lSDL -lSDL_image -lglut -lGL -lGLU
INC=-I../NWCore

#DEPS = NWTypes.h

OBJS = main.o \
	../NWCore/NWImage_SDL.o \
	../NWCore/NWTexture2D.o \
	../NWCore/NWTexture2DBatch.o \
	../NWCore/NWTile.o \
	../NWCore/NWEntity.o 


%.o: %.cpp
	$(CXX) $(CCFLAGS) $(INC) -c $< -o $@

HTW: $(OBJS)
	$(CXX) $(CCFLAGS) $(OBJS) -o $@ $(LIBS)

.PHONY:clean
clean:
	rm $(OBJS) HTW
