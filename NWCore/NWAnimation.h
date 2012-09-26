#ifndef NWANIMATION_H
#define NWANIMATION_H

#include "NWTile.h"
#include <vector>
using namespace std;

namespace NorthWind
{


typedef class NWTile NWFrame;

class NWAnimation
{
public:
	NWAnimation();
	~NWAnimation();
	bool addFrame(NWFrame* frame, int frameId);
	bool rmFrame(int frameId);
	void reset();
	void setFrameInterval();
	NWFrame* getFrame();
    void playInfinitely();
	void playOnce();
	void stop();

private:
	vector<NWFrame*> m_frames;
	unsigned int m_interval;

};

}

#endif