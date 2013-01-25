#include "NWImage_SDL.h"
#include "NWTexture2D.h"
#include <unistd.h>

using namespace NorthWind;

void InitializeSDL(void)
{
    int error;
    SDL_Surface* drawContext;

    error = SDL_Init(SDL_INIT_EVERYTHING);

    // Create a double-buffered draw context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Use 32-bit color: 8 bits of red, green, blue, and alpha.
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    Uint32 flags;
    flags = SDL_OPENGL;// | SDL_FULLSCREEN;
    drawContext = SDL_SetVideoMode(800, 600, 0, flags);

    gluOrtho2D(0.0, 800, 0.0, 600);

}

Uint32 runLoopTimer(Uint32 interval, void* param)
{
    SDL_Event event;
    event.type = SDL_USEREVENT;
    event.user.code = 1;

    SDL_PushEvent(&event);
    return interval;

}
void setTimer(Uint32 interval) 
{
    SDL_TimerID mTimer = SDL_AddTimer(interval, runLoopTimer, NULL); 
}

void show()
{
    //prepare openGL state
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    //initialize
    NWImage_SDL image;
    image.initWithFile("./test.png");
    NWTexture2D texture;
    texture.initWithImage(&image, NWTexturePixelFormat_RGBA8888, image.width(), image.height());
    //test case 1:
    texture.drawAtPoint(10, 10);
    //test case 2:
    texture.drawInRect(50, 20, 100, 100);
    
    //clear openGL state
    glDisable( GL_BLEND );
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    SDL_GL_SwapBuffers();
}

void SDLEventLoop()
{
    bool mRunning=false;
    SDL_Event event;
    while((!mRunning) && (SDL_WaitEvent(&event)))
    {
         switch(event.type)
         {
             case SDL_USEREVENT:
                 show();
                 break;
             case SDL_QUIT :
                 mRunning = true;
                 break;
             default:
                 break;
         }
     }
}

int main()
{
    InitializeSDL();
    setTimer(50);
    SDLEventLoop();

    return 0;
}
