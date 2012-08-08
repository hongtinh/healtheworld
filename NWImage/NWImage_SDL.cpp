#include "NWImage_SDL.h"

namespace NorthWind
{

bool NWImage_SDL::initWithFile( const char* file )
{
	if(m_pImage)
	{
	    return false;
	}
	/* load image from file */
	SDL_RWops* imageFile;
	imageFile = SDL_RWFromFile(file, "rb");
	m_pImage = IMG_Load_RW(imageFile, 1);

	/* init image data */
	m_width = m_pImage->w;
	m_height = m_pImage->h;
	m_pData = m_pImage->pixels;

	return true;
}

/**
 * not supported now.
 */
bool NWImage_SDL::initWithData(const void* data)
{
	return true;
}

}