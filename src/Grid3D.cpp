/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		05/11/2012
 */





//=================================================================
//	Inlude
//---------------------------------------
#include "Grid3D.h"





//=================================================================
//	Grid3D::Grid3D
//---------------------------------------
Grid3D::Grid3D() :
	mGridSize(100, 100, 100),
	mSquareSpacing(10, 10, 10)
{
	
}





//=================================================================
//	Grid3D::GridOrigin : the grid origin
//---------------------------------------
Vector3f& Grid3D::Position() 
{
	return mGridPosition;
}





//=================================================================
//	Grid3D::GridSize : the grid size
//---------------------------------------
Vector3f& Grid3D::Size() 
{
	return mGridSize;
}





//=================================================================
//	Grid3D::SquareSize : the size of the squares
//---------------------------------------
Vector3f& Grid3D::Spacing()
{
	return mSquareSpacing;
}





//=================================================================
//	Grid3D::draw : implement our drawing routine
//---------------------------------------
void Grid3D::Draw( Graphics3D &g ) const
{

	Vector3f vecOrigin( 0, 0, 0 );

	Vector3f vecAxisX(	mGridSize.x, 0, 0 );
	Vector3f vecAxisY(	0, mGridSize.y, 0 );
	Vector3f vecAxisZ(	0, 0, mGridSize.y );

	float numSquareX = mGridSize.x / mSquareSpacing.x;
	float numSquareY = mGridSize.y / mSquareSpacing.y;
	float numSquareZ = mGridSize.z / mSquareSpacing.z;

	for( int i = 0; i <= numSquareX; i++ )
	{
		Vector3f xOffset( (i)*mSquareSpacing.x, 0, 0 );

		g.DrawLine( mGridPosition+xOffset, mGridPosition + vecAxisY+xOffset );
		g.DrawLine( mGridPosition+xOffset, mGridPosition + vecAxisZ+xOffset );
	}

	for( int i = 0; i <= numSquareY; i++ )
	{
		Vector3f yOffset( 0, i*mSquareSpacing.y, 0 );

		g.DrawLine( mGridPosition+yOffset, mGridPosition + vecAxisX+yOffset );
		g.DrawLine( mGridPosition+yOffset, mGridPosition + vecAxisZ+yOffset );
	}

	for( int i = 0; i <= numSquareZ; i++ )
	{
		Vector3f zOffset( 0, 0, i *mSquareSpacing.z);

		g.DrawLine( mGridPosition+zOffset, mGridPosition + vecAxisX+zOffset );		
		g.DrawLine( mGridPosition+zOffset, mGridPosition + vecAxisY+zOffset );
	}

	g.DrawLine( vecOrigin, vecAxisX, sf::Color::Red		);
	g.DrawLine( vecOrigin, vecAxisY, sf::Color::Green	);
	g.DrawLine( vecOrigin, vecAxisZ, sf::Color::Blue	);

	g.DrawText( vecOrigin ,	"O" );
	g.DrawText( vecAxisX  + Vector3f(+5, 0, 0),		"x", sf::Color::Red );
	g.DrawText( vecAxisY  + Vector3f(0, +5, 0),		"y", sf::Color::Green );
	g.DrawText( vecAxisZ  + Vector3f(0, 0, +5),		"z", sf::Color::Blue );
}