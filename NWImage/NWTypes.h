#ifndef NWTYPES_H
#define NWTYPES_H

#include <GL/GL.h>

namespace NorthWind
{
	/*texture vertex data definition*/
	typedef struct NWVertex2F
	{
		GLfloat x;
		GLfloat y;
	} ;

	/*texture coordination data definition */
	typedef struct NWTex2F {
		GLfloat u;
		GLfloat v;
	} ;

	/* Texture unit rendering data definition
	 * vertices: where to render
	 * texCoords: what to render
	 */
	typedef struct NWUnit_V2F_T2F
	{
		NWVertex2F		vertices;
		NWTex2F			texCoords;
	} ;

}
#endif