#ifndef NWACTION_H
#define NWACTION_H
#include "NWAnimation.h"
#include "NWSprite.h"
#include <string>
using namespace std;

namespace NorthWind
{

class NWAction
{
public:
	NWAction(string actionName) { m_name = actionName; }
	virtual ~NWAction() {}
	virtual void play() const = 0;
	void attach(NWSprite* sprite) { m_sprite = sprite; }
	void detach() { m_sprite = NULL; }
	void setAnimation(NWAnimation animation) { m_animation = animation; }
	string getName() { return m_name; }

private:
	NWAnimation m_animation;
	NWSprite* m_sprite;
	string m_name;
};

}

#endif