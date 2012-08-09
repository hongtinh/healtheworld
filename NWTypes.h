#ifndef NWTYPES_H
#define NWTYPES_H

#include <GL/GL.h>

namespace NorthWind
{
	/*texture vertex data definition*/
	typedef struct NWVertex2F_t
	{
		GLfloat x;
		GLfloat y;
	} ;

	/*texture coordination data definition */
	typedef struct NWTexCoord2F_t {
		GLfloat u;
		GLfloat v;
	} ;

	/* Texture unit rendering data definition
	 * vertices: where to render
	 * texCoords: what to render
	 */
	typedef struct NWUnit_V2F_T2F_t
	{
		NWVertex2F_t		vertices;
		NWTexCoord2F_t 	texCoords;
	} ;

}
#endif