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
	NWImage_SDL(){ m_image = NULL; }
	~NWImage_SDL(){ if(m_image) delete m_image; }
	bool initWithFile(const char* file);
	bool initWithData(const void* data);

public:
	SDL_Surface *m_image;
};

}
#endif