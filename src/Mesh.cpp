/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		11/11/2012
 */





//=================================================================
//	Inlude
//---------------------------------------
#include "Mesh.h"





//=================================================================
//	Mesh::Mesh
//---------------------------------------
Mesh::Mesh() :
	mColor( sf::Color::White )
{
}





//=================================================================
//	Mesh::Mesh
//---------------------------------------
void Mesh::SetColor( const sf::Color &color)
{
	mColor = color;
}





//=================================================================
//	Mesh::Draw : draw our mesh on the 3D canvas
//---------------------------------------
void Mesh::Draw( Graphics3D &g ) const
{
	for( size_t i=0; i<mFacets.size(); i++ )
	{
		DrawFacet( g, mFacets[i] );
	}
}





//=================================================================
//	Mesh::DrawFacet : draw a single facet on the 3D canvas
//---------------------------------------
void Mesh::DrawFacet( Graphics3D &g, const Facet &theFacet ) const
{
	// Draw the first line
	g.DrawLine( mVertices[theFacet.indices.back()], 
				mVertices[theFacet.indices[0]], 
				mColor );

	for( size_t i=1; i<theFacet.indices.size()-1; i++ )
	{
		int ind1 = theFacet.indices[i];
		int ind2 = theFacet.indices[i+1];
		g.DrawLine( mVertices[ind1], mVertices[ind2], mColor ); 
	}
}