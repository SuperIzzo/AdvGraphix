/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		12/11/2012
 */





//=================================================================
//	Inlude
//---------------------------------------
#include "OBJMeshLoader.h"
#include <fstream>
#include <sstream>

#include <iostream>





//=================================================================
//	OBJMeshLoader::LoadMesh : loads mesh data an obj file
//---------------------------------------
bool OBJMeshLoader::LoadMesh(Mesh &mesh, const char * objFname)
{
	// Clear the mesh
	mesh.mVertices.clear();
	mesh.mFacets.clear();

	std::ifstream objFile( objFname );

	if( objFile.is_open() )
	{
		std::istringstream lineParser;
		std::istringstream indexParser;

		int numVerts  = 0;
		int numFacets = 0;
		while( objFile.good() )
		{
			char line[255];
			objFile.getline(line, 255);

			lineParser.clear();
			indexParser.clear();

			switch( line[0] )
			{
				case 'v':
					// Only use vertex coords
					if( line[1] == ' ' )
					{
						Vector3f theVertex;

						lineParser.str( line + 2 );

						lineParser >> theVertex.x;
						lineParser >> theVertex.y;
						lineParser >> theVertex.z;

						mesh.mVertices.push_back( theVertex );


						//DEBUG STUFF
						numVerts++;
						std::cout << "Vertex " << numVerts << ":\tx=" <<
							theVertex.x << "\ty=" <<
							theVertex.y << "\tz=" <<
							theVertex.z << std::endl;					
					}
					break;

				case 'f':
					{
					Mesh::Facet theFacet;

					lineParser.str( line + 2 );

					while( lineParser.good() )
					{
						// Get a single index
						char indxText[30];
						lineParser >> indxText;

						indexParser.str( indxText );

						int ind;

						indexParser >> ind;

						theFacet.indices.push_back( ind-1 );
					}

					mesh.mFacets.push_back( theFacet );

					// DEBUG STUFF
					numFacets++;
					std::cout << "Facet " << numFacets 
						<< " (v " << theFacet.indices.size() << "):\t" 
						<< theFacet.indices[0]+1;

					for( size_t i=1; i< theFacet.indices.size(); i++ )
					{
						std::cout << ", " << theFacet.indices[i]+1;
					}
					std::cout << std::endl;

					break;
					}

				default:
					// skip...
					break;
			}

			//if( line[0] == '#' )
			//	std::cout << line << std::endl;
			//if
		}
	}

	return true;
}