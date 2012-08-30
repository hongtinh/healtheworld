
#include "NWEntity.h"

namespace NorthWind
{

	NWEntity::NWEntity(NWTile* tile, int x, int y, int width, int height)
	{
		m_pTile = tile;
		m_x = x;
		m_y = y;
		m_height = height;
		m_width = width;
		m_quad.bl.texCoords = m_pTile->m_texBL;
		m_quad.br.texCoords = m_pTile->m_texBR;
		m_quad.tl.texCoords = m_pTile->m_texTL;
		m_quad.br.texCoords = m_pTile->m_texTR;
		updateQuad(0, 0);
	}

	void NWEntity::updateQuad(int viewPortX, int viewPortY)
	{
		m_quad.bl.vertices.x = m_x - viewPortX;
		m_quad.bl.vertices.y = m_y - viewPortY;

		m_quad.br.vertices.x = m_quad.bl.vertices.x + m_width;
		m_quad.br.vertices.y = m_quad.bl.vertices.y;

		m_quad.tl.vertices.x = m_quad.bl.vertices.x;
		m_quad.tl.vertices.y = m_quad.bl.vertices.y + m_height;

		m_quad.tr.vertices.x = m_quad.br.vertices.x;
		m_quad.tr.vertices.y = m_quad.tl.vertices.y;
	}





}