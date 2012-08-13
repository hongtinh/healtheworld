#ifndef NWIMAGE_SDL_H
#define NWIMAGE_SDL_H

#include "NWImage.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace NorthWind
{

class NWImage_SDL:public NWImage
{
public:
	NWImage_SDL(){ m_pImage = NULL; }
	~NWImage_SDL(){ if(m_pImage) delete m_pImage; }
	bool initWithFile(const char* file);
	bool initWithData(const void* data);

private:
	SDL_Surface *m_pImage;
};

}
#endif