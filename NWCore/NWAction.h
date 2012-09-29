#ifndef NWACTION_H
#define NWACTION_H
#include "NWAnimation.h"

namespace NorthWind
{

class NWAction
{
public:
	NWAction();
	~NWAction();
	void stop();
	void moveTo(int x, int y);
	void goTo(int x, int y);
	void setSpeed(int speed);
	void play();

public:
	NWAnimation m_animation;
	int m_speed;

};

}

#endif