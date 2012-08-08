#ifndef NWIMAGE_H
#define NWIMAGE_H
#include <stdlib.h>
#include <stdio.h>
namespace NorthWind{

/**
 * Abstract class, provide the image data info
 */

class NWImage
{
public:
	NWImage(){}
	virtual ~NWImage(){}
	virtual bool initWithFile(const char* file)  = 0;
	void* getPixel() const { return m_data; }
	unsigned int width() const { return m_width; }
	unsigned int height() const { return m_height; }
	
public:
	void* m_data;
	unsigned int m_width;
	unsigned int m_height;
};


}

#endif
