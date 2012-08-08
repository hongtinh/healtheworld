#include "NWImage_SDL.h"

namespace NorthWind
{

bool NWImage_SDL::initWithFile( const char* file )
{
	if(m_image)
	{
	    return false;
	}
	/* load image from file */
	SDL_RWops* imageFile;
	imageFile = SDL_RWFromFile(file, "rb");
	m_image = IMG_Load_RW(imageFile, 1);

	/* init image data */
	m_width = m_image->w;
	m_height = m_image->h;
	m_data = m_image->pixels;

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