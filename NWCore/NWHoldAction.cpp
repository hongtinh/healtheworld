#include "NWHoldAction.h"


namespace NorthWind
{

void NWHoldAction::play()
{
	if(m_animation)
	{
		m_animation->play();
	}
}

}