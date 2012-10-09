#ifndef NWHOLDACTION_H
#define NWHOLDACTION_H

#include "NWAction.h"

namespace NorthWind
{

class NWHoldAction::public NWAction
{
public:
	NWHoldAction() {}
	~NWHoldAction() {}
	void play();
private:
};

}
#endif