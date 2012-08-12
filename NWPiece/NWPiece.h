#ifndef NWPIECE_H
#define NWPIECE_H

#include "../NWTexture/NWTexture2D.h"
#include "../NWTypes.h"

namespace NorthWind
{


class NWPiece
{
public:
	NWPiece(NWTexture2D* texture, GLfloat x, GLfloat y, GLfloat w, GLfloat h, unsigned id);
	~NWPiece();
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