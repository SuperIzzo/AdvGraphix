/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		12/11/2012
 */
#ifndef __OBJMESHLOADER_H__
#define __OBJMESHLOADER_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "Mesh.h"





//=================================================================
//	Class OBJMeshLoader
//---------------------------------------
class OBJMeshLoader
{
public:
	static bool				LoadMesh(Mesh &mesh, const char * objFname);
};





#endif