#ifndef NWIMAGE_H
#define NWIMAGE_H

namespace NorthWind{

/**
 * Abstract class, provide the image data info
 */



class NWImage
{
public:
	NWImage();
	virtual ~NWImage();
	virtual bool initWithFile(const char* file) const = 0;
	//virtual bool initWithData(const void* data) const = 0;
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
