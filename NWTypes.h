#ifndef NWTYPES_H
#define NWTYPES_H

#include <GL/GL.h>

namespace NorthWind
{
	/* texture point vertex data definition */
	typedef struct{
		GLfloat x;
		GLfloat y;
	}NWVertex2F_t;

	/* texture point coordination data definition */
	typedef struct {
		GLfloat u;
		GLfloat v;
	}NWTexCoord2F_t ;

	/* texture point definition */
	typedef struct {
		NWVertex2F_t		vertices;
		NWTexCoord2F_t 	texCoords;
	}NWPoint_V2F_T2F_t ;

	/* Texture rendering unit data definition	 */
	typedef struct {
		/* bottom left */
		NWPoint_V2F_T2F_t bl;
		/* bottom right */
		NWPoint_V2F_T2F_t br;
		/* top left */
		NWPoint_V2F_T2F_t tl;
		/* top right */
		NWPoint_V2F_T2F_t tr;
	}NWQuad_V2F_T2F_t;


}
#endif