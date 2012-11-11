#ifndef __MESH_H__
#define __MESH_H__

#include <vector>

#include <SFML/Graphics/Color.hpp>

#include "Vector.h"
#include "Graphics3D.h"

class Mesh
{
public:	
	class Facet
	{
	public:
		std::vector<int>	indices;
	};


public:
							Mesh();
	void					Draw( Graphics3D &g ) const;

private:
	void					DrawFacet( Graphics3D &g, const Facet &theFacet ) const;


public:
	std::vector<Vector3f>	mVertices;
	std::vector<Facet>		mFacets;

private:
	sf::Color				mColor;
};


#endif