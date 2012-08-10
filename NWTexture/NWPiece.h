#ifndef NWPIECE_H
#define NWPIECE_H

#include "NWTexture2D.h"
#include "../NWTypes.h"

namespace NorthWind
{

class NWPiece
{
public:
	NWPiece(NWTexture2D* texture, NWQuad_V2F_T2F_t data, unsigned int id):
		m_pTexture(texture),
		m_data(data), 
		m_id(id) {}

	~NWPiece();
	NWTexture2D* getTexture() { return m_pTexture; }
	unsigned int getId() { return m_id; }
	NWQuad_V2F_T2F_t& getData() { return m_data; }

public:
	NWTexture2D* m_pTexture;
	NWQuad_V2F_T2F_t m_data;
	unsigned int m_id;
};

}
#endif