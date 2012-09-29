#ifndef NWSPRITE_H
#define NWSPRITE_H

#include "NWAnimation.h"

namespace NorthWind
{

typedef enum
{
	NW_SPRITE_HOLD = 0,
	NW_SPRITE_GO = 1,
	NW_SPRITE_END
}NWSprite_action_e;

class NWSprite
{
public:
	NWSprite();
	~NWSprite();
	NWUnitQuad_V2F_T2F_t & getQuad() { return m_quad; }

	void moveTo(int x, int y) { m_x = x; m_y = y; }
	void goTo(int x, int y);
	void hold();

	void setSpeed(int speed);
	void play();

private:
	void updateQuad();
	void stopGoing();
	void going();

public:
	GLfloat m_x;
	GLfloat m_y;
	GLfloat m_width;
	GLfloat m_height; 
	vector<NWAnimation*> m_animations;
	NWUnitQuad_V2F_T2F_t m_quad;
	NWSprite_action_e m_action;
	int m_speed;
	GLfloat m_targetX;
	GLfloat m_targetY;

};

}
#endif