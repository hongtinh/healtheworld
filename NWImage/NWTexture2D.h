#ifndef NWTEXTURE2D_H
#define NWTEXTURE2D_H

#include "NWImage_SDL.h"
#include "SDL/SDL_opengl.h"
#include <GL/GL.h>
namespace NorthWind
{

typedef enum 
{
	/* 32-bit: RGBA8888 */
	NWTexturePixelFormat_RGBA8888,
	/* 32-bit without Alpha channel */
	NWTexturePixelFormat_RGB888,
	/* 16-bit: RGBA4444 */
	NWTexturePixelFormat_RGBA4444,
	/* 16-bit without Alpha channel */
	NWTexturePixelFormat_RGB565,
	/* Default format */
	NWTexturePixelFormat_Default = NWTexturePixelFormat_RGBA8888
} NWTexturePixelFormat;

class NWTexture2D
{
public:
	NWTexture2D();
	~NWTexture2D();

	bool initWithData(const void* data, NWTexturePixelFormat pixelFormat, unsigned int pixelsWide, unsigned int pixelsHigh);
	bool initWithImage(const NWImage* image, NWTexturePixelFormat pixelFormat, unsigned int pixelsWide, unsigned int pixelsHigh);
	GLuint getName() const { return m_name; }
	unsigned int getPixelsWide() const { return m_pixelsWide; }
	unsigned int getPixelsHigh() const { return m_pixelsHigh; }
	void drawAtPoint(float x, float y);

private:
	GLuint m_name;
	unsigned int m_pixelsWide;
	unsigned int m_pixelsHigh;
};


}
#endif
