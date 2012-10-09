#include "NWAnimation.h"

namespace NorthWind
{

	NWAnimation::NWAnimation()
	{
		reset();
	}

	NWAnimation::~NWAnmation()
	{
	}

	void NWAnimation::reset()
	{
		m_frames.clear();
		m_interval = 0;
	}

	void NWAnimation::setFrameInterval(unsigned int interval)
	{
		m_interval = interval;
	}

	bool NWAnimation::addFrame(NWFrame* frame)
	{
		if(NULL== frame) 
		{
			return false;
		}
		m_frames.push_back(frame);
		return true;
	}

	bool NWAnimation::rmFrame(int frameId)
	{
		if(frameId >= m_frames.size())
		{
			return false;
		}

		vector<NWFrame*>::iterator it;
		m_frames.erase(it + frameId);
		return true;
	}

	bool NWAnimation::insertFrame(NWFrame* frame, int pos)
	{
		if(pos >= m_frames.size())
		{
			return false;
		}
		vector<NWFrame*>::iterator it;
		m_frames.insert(it + pos);
		return true;
	}

	void NWAnimation::play()
	{
		static unsigned int ticks = 0;
		static unsigned int playCount = 0;
		ticks++;
		if(ticks == m_interval)
		{
			ticks = 0;

			m_renderFrame = m_frames.at(playCount);
			playCount++;

			if(playCount == m_frames.size())
			{
				playCount = 0;
			}
		}
	}


}