#include "NWImage_SDL.h"
#include "NWTexture2D.h"
#include "NWTile.h"
#include "NWEntity.h"
#include "NWTexture2DBatch.h"
#include <unistd.h>

using namespace NorthWind;


NWImage_SDL* image=NULL;
NWTexture2D* texture=NULL;
NWTile* tile=NULL;
NWTexture2DBatch* texbatch=NULL;

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

void init()
{
    image = new NWImage_SDL();
    image->initWithFile("./test.png");
    texture = new NWTexture2D();
    texture->initWithImage(image, NWTexturePixelFormat_RGBA8888, image->width(), image->height());
    tile = new NWTile(texture,0,0,image->width(),image->height());
    texbatch = new NWTexture2DBatch();
    texbatch->initWithTexture(texture, 10);
}

void show()
{
    /*/prepare openGL state
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);*/
    //initialize

    glClear(GL_COLOR_BUFFER_BIT);
    //test case 1:
    texture->drawAtPoint(10, 10);
    //test case 2:
    texture->drawInRect(50, 20, 100, 100);
    //test case 3:

    texbatch->reset();
    for(int i=0; i< 10; i++)
    {
        int x = 200;//rand()%800;
        int y = 200;//rand()%600;
        int w = image->width();//rand()%800;
        int h = image->height();//rand()%600;
        if(x+w > 800) x = 800-w;
        if(y+h > 600) y = 600-h;
        NWEntity ent(tile, x,y,w,h);
        texbatch->addQuad(&(ent.getQuad()));
    }
    texbatch->draw();
    

    /*/clear openGL state
    glDisable( GL_BLEND );
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);*/
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
    init();

    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    setTimer(50);
    SDLEventLoop();

    glDisable( GL_BLEND );
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    delete image;
    delete texture;
    delete tile;
    delete texbatch;

    return 0;
}
