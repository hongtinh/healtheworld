#include "NWSprite.h"


namespace NorthWind
{

NWSprite::NWSprite()
{
}

NWSprite:~NWSprite()
{
}


void NWSprite::updateQuad()
{
}

void NWSprite::addAction(NWAction action)
{
	action.attach(this);
	m_actions.insert(pair<string, NWAction>(action.getName(), action));
}

void NWSprite::play()
{
	map<string, NWAction>::iterator it;
	it = m_actions.find(m_beingAction);
	if( it!= m_actions.end())
	{
		it->second.play();
	}
}

}