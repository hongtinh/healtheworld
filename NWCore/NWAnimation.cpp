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

	bool NWAnimation::addFrame(NWFrame* frame, int frameId)
	{
		m_frames.insert(frameId, frame);
	}

	bool NWAnimation::rmFrame(int frameId)
	{
		m_frames.erase(frameId);
	}

	void NWAnimation::playInfinitely()
	{
		int ticks = 0;
		/**
		TODO:

		*/
		ticks++;
		m_renderFrame = m_frames.at(ticks%frameSize);
		if(ticks >= frameSize) ticks = 0;
	}



}