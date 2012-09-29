#include "NWSprite.h"


namespace NorthWind
{

		NWSprite::NWSprite()
		{

		}

		NWSprite:~NWSprite()
		{

		}

		 void NWSprite::play()
		 {
			 switch(m_action)
			 {
			 case NW_SPRITE_HOLD:
				 /**
				 action do nothing;
				 animation stop;
				 */
				 this->stopGoing();
			 case NW_SPRITE_GO:
				 this->going();
			 default:

			 }

		 }

		 void NWSprite::goTo(int x, int y)
		 {
			 m_action = NW_SPRITE_GO;
			 m_targetX = x;
			 m_targetY = y;
		 }
		 void NWSprite::going()
		 {

		 }
		  
		 void NWSprite::stopGoing()
		 {

		 }

}