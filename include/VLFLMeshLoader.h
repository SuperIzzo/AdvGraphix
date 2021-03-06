/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		11/11/2012
 */
#ifndef __VLFLMESHLOADER_H__
#define __VLFLMESHLOADER_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "Mesh.h"





//=================================================================
//	Class VLFLMeshLoader
//---------------------------------------
class VLFLMeshLoader
{
public:
	static bool				LoadMesh(Mesh &mesh, const char * vertListFname, const char * faceListFname);
};





#endif