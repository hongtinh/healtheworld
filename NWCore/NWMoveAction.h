#ifndef NWMOVEACTION_H
#define NWMOVEACTION_H
#include "NWAction.h"

namespace NorthWind
{

class NWMoveAction:public NWAction
{
public:
	NWMoveAction() {}
	~NWMoveAction() {}
	void play();
	void setFollowedAction(string action);
private:
	string m_followedAction;
};

}

#endif