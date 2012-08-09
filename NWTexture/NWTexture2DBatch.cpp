#include "NWTexture2DBatch.h"

namespace NorthWind
{


NWTexture2DBatch::NWTexture2DBatch()
{
	m_pQuads = NULL;
	m_pTexture = NULL;
	m_pIndices = NULL;
	m_capacity = 0;
	m_totalQuads = 0;
}

NWTexture2DBatch::~NWTexture2DBatch()
{
}

bool NWTexture2DBatch::initWithTexture( NWTexture2D* texture, unsigned int capacity )
{
	if( !( texture && capacity ) ) return false;
	m_pTexture = texture;
	m_pQuads = new NWUnit_V2F_T2F_t[capacity];
	/*6 vertex make a quad*/
	m_pIndices = new GLushort[capacity*6];
	initIndices();
}

void NWTexture2DBatch::initIndices()
{
	for( unsigned int i=0; i < m_capacity; i++)
	{
		m_pIndices[i*6+0] = i*4+0;
		m_pIndices[i*6+1] = i*4+0;
		m_pIndices[i*6+2] = i*4+2;		
		m_pIndices[i*6+3] = i*4+1;
		m_pIndices[i*6+4] = i*4+3;
		m_pIndices[i*6+5] = i*4+3;
	}
}

void NWTexture2DBatch::reset()
{
	if(m_pQuads)
	{
		memset(m_pQuads, 0, sizeof(NWUnit_V2F_T2F_t) * m_capacity);
		m_totalQuads = 0;
	}
}

bool NWTexture2DBatch::addQuad(NWUnit_V2F_T2F_t * quad)
{
	if(m_totalQuads >= m_capacity) return false;
	m_pQuads[m_totalQuads] = (*quad);
	m_totalQuads++;
	return true;
}

}