#include "NWImage_SDL.h"
#include "NWTexture2D.h"

using namespace NorthWind;

int main()
{
    //initialize
    NWImage_SDL image;
    image.initWithFile("./test.png");
    NWTexture2D texture;
    texture.initWithImage(&image, NWTexturePixelFormat_RGBA8888, image.width(), image.height());
    //test case 1:
    texture.drawAtPoint(10, 10);
    texture.drawInRect(50, 10, 20, 20);

    return 0;
}
