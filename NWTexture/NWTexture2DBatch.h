#ifndef NWTEXTURE2DBATCH_H
#define NWTEXTURE2DBATCH_H

#include "NWTexture2D.h"
#include "../NWTypes.h"
namespace NorthWind
{

class NWTexture2DBatch
{
public:
	NWTexture2DBatch();
	virtual ~NWTexture2DBatch();
	bool initWithTexture( NWTexture2D* texture, unsigned int capacity);
	void initIndices();
	bool addQuad(NWQuad_V2F_T2F_t* quad);
	void reset();
public:
	NWTexture2D * m_pTexture;
	NWQuad_V2F_T2F_t * m_pQuads;
	GLushort *m_pIndices;
	unsigned int m_capacity;
	unsigned int m_totalQuads;
};

}
#endif