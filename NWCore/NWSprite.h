#ifndef NWSPRITE_H
#define NWSPRITE_H

#include "NWAnimation.h"
#include "NWAction.h"

namespace NorthWind
{

class NWSprite
{
public:
	NWSprite();
	~NWSprite();
	NWUnitQuad_V2F_T2F_t & getQuad() { return m_quad; }
	void addAction(NWAction action);
	void play();
private:
	void updateQuad();

private:
	GLfloat m_currentX;
	GLfloat m_currentY;
	GLfloat m_targetX;
	GLfloat m_targetY;
	GLfloat m_width;
	GLfloat m_height; 
	NWUnitQuad_V2F_T2F_t m_quad;
	string m_beingAction;
    map<string action, NWAction> m_actions;
};

}
#endif