#ifndef NWENTITY_H
#define NWENTITY_H

#include "../NWCore/NWTile/NWTile.h"

namespace NorthWind
{

class NWEntity
{
public:
	NWEntity(NWTile* tile, int x, int y, int width, int height):
	  m_pTile(tile),m_x(x),m_y(y),m_height(height),m_width(width) { }

	~NWEntity();
	void moveTo(int x, int y) { m_x = x; m_y = y; }

public:
	NWTile m_pTile;
	GLfloat m_x;
	GLfloat m_y;
	GLfloat m_height;
	GLfloat m_width;
};

}
#endif