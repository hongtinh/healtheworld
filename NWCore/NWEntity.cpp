
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
		/*
		for(int i=0; i<4;i++)
			{
		m_quad.bl.color[i] = 1;
		m_quad.br.color[i] = 1;
		m_quad.tl.color[i] = 1;
		m_quad.tr.color[i] = 1;
			}
		*/
		updateQuad(0, 0);
	}
	NWEntity::~NWEntity()
	{
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