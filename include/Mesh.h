/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		03/11/2012
 */
#ifndef __MESH_H__
#define __MESH_H__





//=================================================================
//	Inlude
//---------------------------------------
#include <vector>
#include <SFML/Graphics/Color.hpp>
#include "Vector.h"
#include "Graphics3D.h"





//=================================================================
//	Class Mesh
//---------------------------------------
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
							
	void					SetColor( const sf::Color &color);
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