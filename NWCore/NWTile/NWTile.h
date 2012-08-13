#ifndef NWTILE_H
#define NWTILE_H

#include "../NWTexture/NWTexture2D.h"
#include "../NWTypes.h"

namespace NorthWind
{

class NWTile
{
public:
	/*x,y; w,h; specified which texture area is this NWTile belong to.*/
	NWTile(NWTexture2D* texture, GLfloat x, GLfloat y, GLfloat w, GLfloat h, unsigned id);
	~NWTile();
	NWTexture2D* getTexture() { return m_pTexture; }
	unsigned int getId() { return m_id; }

public:
	NWTexture2D* m_pTexture;
	NWPointTexCoord2F_t m_texBL;
	NWPointTexCoord2F_t m_texBR;
	NWPointTexCoord2F_t m_texTL;
	NWPointTexCoord2F_t m_texTR;
	unsigned int m_id;
};

}
#endif