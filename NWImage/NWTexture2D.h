#ifndef NWTEXTURE2D_H
#define NWTEXTURE2D_H

#include "NWImage_SDL.h"
namespace NorthWind
{


typedef enum {
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
		NWTexture2D(){}
		~NWTexture2D(){}
		bool initWithData(const void *data, NWTexturePixelFormat pixelFormat, unsigned int pixelsWide, unsigned int pixelsHigh);
	};


}
#endif