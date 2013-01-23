CC=g++
#CFLAGS= -g `sdl-config --cflags --libs` -lSDL -lSDL_image -lglut -lGL -lGLU 
CFLAGS= -g -Wall 
LIBS= -lSDL -lSDL_image -lGL
INC=-I.

DEPS = NWImage.h \
	NWImage_SDL.h \
	NWTexture2D.h \
	NWTypes.h

OBJS = main.o \
	NWImage_SDL.o \
	NWTexture2D.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(INC)

HTW: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm *.o HTW
