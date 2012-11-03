#ifndef __MESH_H__
#define __MESH_H__

#include <vector>
#include "Vector.h"


class Mesh
{
public:
	
	class Facet
	{
	private:
		
		Mesh *					mMesh
	};

	void	Load(const char* theVertexFile, const char* theIndexFile);

public:
	vector< Vector3f >		mVertices;
	vector< Facet* >		mFacets;
};

#endif