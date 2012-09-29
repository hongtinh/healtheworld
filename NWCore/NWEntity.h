#ifndef NWENTITY_H
#define NWENTITY_H

#include "NWTile.h"

namespace NorthWind
{

class NWEntity
{
public:

	NWEntity(NWTile* tile, int x, int y, int width, int height);
	~NWEntity();

	void moveTo(int x, int y) { m_x = x; m_y = y; };
	NWUnitQuad_V2F_T2F_t & getQuad() { return m_quad; }
	void updateQuad(int viewPortX, int viewPortY);

public:

private:
	NWUnitQuad_V2F_T2F_t m_quad;
	NWTile m_pTile;
	GLfloat m_x;
	GLfloat m_y;
	GLfloat m_height;
	GLfloat m_width;
};

}
#endi
