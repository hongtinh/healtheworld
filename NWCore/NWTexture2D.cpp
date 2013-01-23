#include "NWTexture2D.h"
#include "NWTypes.h"

namespace NorthWind
{

NWTexture2D::NWTexture2D()
{
	m_name = 0;
}
NWTexture2D::~NWTexture2D()
{
	if(m_name)
	{
		glDeleteTextures(1, &m_name);
	}
}

bool NWTexture2D::initWithData( 
	const void* data, 
	NWTexturePixelFormat pixelFormat, 
	unsigned int pixelsWide, 
	unsigned int pixelsHigh 
)
{    
	if(m_name)
	{
		return false;
	}
    glPixelStorei(GL_UNPACK_ALIGNMENT,4);

    glGenTextures(1, &m_name);
    glBindTexture(GL_TEXTURE_2D, m_name);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

    /* Specify OpenGL texture */
    switch(pixelFormat)
    {
    case NWTexturePixelFormat_RGBA8888:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)pixelsWide, (GLsizei)pixelsHigh, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        break;
    case NWTexturePixelFormat_RGB888:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)pixelsWide, (GLsizei)pixelsHigh, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        break;
    case NWTexturePixelFormat_RGBA4444:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)pixelsWide, (GLsizei)pixelsHigh, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
        break;
    case NWTexturePixelFormat_RGB565:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)pixelsWide, (GLsizei)pixelsHigh, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
        break;
    default:
		printf("pixelFormat %d not supported,", pixelFormat);
		break;
    }
	
	m_pixelsWide = pixelsWide;
	m_pixelsHigh = pixelsHigh;
    return true;
}

bool NWTexture2D::initWithImage( 
	const NWImage* image, 
	NWTexturePixelFormat pixelFormat, 
	unsigned int pixelsWide, 
	unsigned int pixelsHigh 
)
{
	return ( initWithData(image->getPixel(), pixelFormat, pixelsWide, pixelsHigh) );
}

void NWTexture2D::drawAtPoint( float x, float y )
{
/**
 * needed GL state:
 * glEnableClientState(GL_VERTEX_ARRAY);
 * glEnableClientState(GL_TEXTURE_COORD_ARRAY);
 */
	GLfloat	coordinates[] = {	
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f };

	GLfloat	vertices[] = {	
		x,	y,
		m_pixelsWide + x,	 y,	
		x,	m_pixelsHigh + y,
		m_pixelsWide + x,	 m_pixelsHigh + y};

		glBindTexture(GL_TEXTURE_2D, m_name);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, coordinates);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void NWTexture2D::drawInRect( float x, float y, float w, float h )
{

/**
 * needed GL state:
 * glEnableClientState(GL_VERTEX_ARRAY);
 * glEnableClientState(GL_TEXTURE_COORD_ARRAY);
 */
	GLfloat	coordinates[] = {	
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f };

	GLfloat	vertices[] = {	
		x,			y,	
		x + w,	y,
		x,			y + h,
		x + w,	y + h};

		glBindTexture(GL_TEXTURE_2D, m_name);
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, coordinates);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

}
