#include "Mesh.h"




Mesh::Mesh() :
	mColor( sf::Color::White )
{
}





void Mesh::Draw( Graphics3D &g ) const
{
	for( int i=0; i<mFacets.size(); i++ )
	{
		DrawFacet( g, mFacets[i] );
	}
}





void Mesh::DrawFacet( Graphics3D &g, const Facet &theFacet ) const
{
	// Draw the first line
	g.DrawLine( mVertices[theFacet.indices.back()], 
				mVertices[theFacet.indices[0]], 
				mColor );

	for( int i=1; i<theFacet.indices.size()-1; i++ )
	{
		int ind1 = theFacet.indices[i];
		int ind2 = theFacet.indices[i+1];
		g.DrawLine( mVertices[ind1], mVertices[ind2], mColor ); 
	}
}