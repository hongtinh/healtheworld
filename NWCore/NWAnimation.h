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
	bool addFrame(NWFrame* frame);
	bool rmFrame(int frameId);
	bool insertFrame(NWFrame* frame, int pos);
	void reset();
	void setFrameInterval();
	NWFrame* getFrame();
    void play();

private:
	vector<NWFrame*> m_frames;
	unsigned int m_interval;
	NWFrame* m_renderFrame;
};

}

#endif