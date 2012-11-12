//=================================================================
//	Inlude
//---------------------------------------
#include "VLFLMeshLoader.h"
#include <fstream>

#include <iostream>





//=================================================================
//	VLFLMeshLoader::LoadMesh : loads mesh data from vl and fl files
//---------------------------------------
bool VLFLMeshLoader::LoadMesh(Mesh &mesh, const char * vertListFname, const char * faceListFname)
{
	mesh.mVertices.clear();

	std::ifstream vertListFile( vertListFname );
	std::ifstream faceListFile( faceListFname );

	if( vertListFile.is_open() )
	{
		int numVerts = 0;
		while( vertListFile.good() )
		{
			Vector3f theVertex;

			vertListFile >> theVertex.x;
			vertListFile >> theVertex.y;
			vertListFile >> theVertex.z;

			mesh.mVertices.push_back( theVertex );


			// DEBUG STUFF
			numVerts++;
			std::cout << "Vertex " << numVerts << ":\tx=" <<
				theVertex.x << "\ty=" <<
				theVertex.y << "\tz=" <<
				theVertex.z << std::endl;
		}
	}

	if( faceListFile.is_open() )
	{
		bool newFace = true;
		int	 lastInd;
		Mesh::Facet theFacet;

		int numFacets = 0;
		while( faceListFile.good() )
		{
			int ind;
			faceListFile >> ind;

			// The file format suggests counting from 1,
			// We'll start from 0 so that it's easier to index
			ind--;

			if( newFace )
			{
				lastInd = ind;
				theFacet.indices.clear();
				theFacet.indices.push_back( ind );
				newFace = false;
			}
			else
			{
				if( ind == lastInd )
				{
					mesh.mFacets.push_back( theFacet );
					newFace = true;


					// DEBUG STUFF
					numFacets++;
					std::cout << "Facet " << numFacets 
						<< " (v " << theFacet.indices.size() << "):\t" 
						<< lastInd+1;

					for( int i=1; i< theFacet.indices.size(); i++ )
					{
						std::cout << ", " << theFacet.indices[i]+1;
					}
					std::cout << std::endl;
				}
				else
				{
					theFacet.indices.push_back( ind );
				}
			}
		}
	}

	return true;
}