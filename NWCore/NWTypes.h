#ifndef NWTYPES_H
#define NWTYPES_H

#include <GL/gl.h>
#include <GL/glut.h>

namespace NorthWind
{
	/* texture point vertex data definition */
	typedef struct{
		GLfloat x;
		GLfloat y;
	}NWPointVertex2F_t;

	/* texture point coordination data definition */
	typedef struct {
		GLfloat u;
		GLfloat v;
	}NWPointTexCoord2F_t ;

	/* texture point definition */
	typedef struct {
		NWPointVertex2F_t		vertices;
		//GLfloat color[4];
		NWPointTexCoord2F_t 	texCoords;
	}NWUnitPoint_V2F_T2F_t ;

	/* Texture rendering unit data definition	 */
	typedef struct {
		/* bottom left */
		NWUnitPoint_V2F_T2F_t bl;
		/* bottom right */
		NWUnitPoint_V2F_T2F_t br;
		/* top left */
		NWUnitPoint_V2F_T2F_t tl;
		/* top right */
		NWUnitPoint_V2F_T2F_t tr;
	}NWUnitQuad_V2F_T2F_t;


}
#endif
