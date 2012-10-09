#include "NWMoveAction.h"

namespace NorthWind
{

void NWMoveAction::play()
{
	if(m_sprite)
	{
		if(m_animation)
		{
			m_animation->play();
		}
		m_sprite->m_currentX = m_sprite->m_targetX;
		m_sprite->m_currentY = m_sprite->m_targetY;
		m_sprite->m_beingAction = m_followedAction;
	}

}

void NWMoveAction::setFollowedAction(string action)
{
	if(!action.empty())
	{
		m_followedAction = action;
	}
}

}