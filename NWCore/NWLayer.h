#include "NWEnity.h"
#include "NWTexture2DBatch.h"
namespace NorthWind
{


class NWLayer
{
public:
	NWLayer();
	~NWLayer();
	void pushEntityToView();
	void addEntity();

private:
	NWTexture2DBatch* m_texBatch;



};


}