#include "NWTile.h"

namespace NorthWind
{

	NWTile::~NWTile()
	{
		m_id = 0;
		m_pTexture = NULL;
	}

	NWTile::NWTile( NWTexture2D* texture, GLfloat x, GLfloat y, GLfloat w, GLfloat h, unsigned id )
	{
		if(NULL == texture) return;
		m_pTexture = texture;
		m_id = id;
		unsigned int texWidth = texture->getPixelsWide();
		unsigned int texHeight = texture->getPixelsHigh();

		m_texBL.u = x / (float)texWidth;
		m_texBL.v = (y + h) / (float)texHeight;

		m_texBR.u = (x + w) / (float)texWidth;
		m_texBR.v = m_texBL.v;

		m_texTL.u = m_texBL.u;
		m_texTL.v = y / (float)texHeight;

		m_texTR.u = m_texBR.u;
		m_texTR.v = m_texTL.v;
	}

}