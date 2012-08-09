#ifndef NWPIECE_H
#define NWPIECE_H

#include "NWTexture2D.h"
#include "../NWTypes.h"

namespace NorthWind
{

class NWPiece
{
public:
	NWPiece(NWTexture2D* texture, NWTexCoord2F_t data, unsigned int id):
		m_pTexture(texture),
		m_data(data), 
		m_id(id) {}

	~NWPiece();
	NWTexture2D* getTexture() {}
	unsigned int getId() { return m_id; }
	NWTexCoord2F_t& getData() { return m_data; }

public:
	NWTexture2D* m_pTexture;
	NWTexCoord2F_t m_data;
	unsigned int m_id;
};

}
#endif