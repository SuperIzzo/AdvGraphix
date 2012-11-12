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
Grid3D::Grid3D() 
{
}





//=================================================================
//	Grid3D::draw : implement our drawing routine
//---------------------------------------
void Grid3D::Draw( Graphics3D &g ) const
{
	const float GRID_SIZE   =						300;
	const float NUM_SQUARES =						 10;
	const float SQUARE_SIZE =	GRID_SIZE / NUM_SQUARES;

	Vector3f vecOrigin( 0, 0, 0 );

	Vector3f vecAxisX(	GRID_SIZE, 0, 0 );
	Vector3f vecAxisY(	0, GRID_SIZE, 0 );
	Vector3f vecAxisZ(	0, 0, GRID_SIZE );

	g.DrawLine( vecOrigin, vecAxisX, sf::Color::Red		);
	g.DrawLine( vecOrigin, vecAxisY, sf::Color::Green	);
	g.DrawLine( vecOrigin, vecAxisZ, sf::Color::Blue	);

	for( int i = 1; i <= NUM_SQUARES; i++ )
	{
		Vector3f xOffset( i*SQUARE_SIZE, 0, 0 );
		Vector3f yOffset( 0, i*SQUARE_SIZE, 0 );
		Vector3f zOffset( 0, 0, i *SQUARE_SIZE);

		g.DrawLine( vecOrigin+yOffset, vecAxisX+yOffset );
		g.DrawLine( vecOrigin+zOffset, vecAxisX+zOffset );

		g.DrawLine( vecOrigin+xOffset, vecAxisY+xOffset );
		g.DrawLine( vecOrigin+zOffset, vecAxisY+zOffset );

		g.DrawLine( vecOrigin+xOffset, vecAxisZ+xOffset );
		g.DrawLine( vecOrigin+yOffset, vecAxisZ+yOffset );
	}

	g.DrawText( vecOrigin ,	"O" );
	g.DrawText( vecAxisX  + Vector3f(+5, 0, 0),		"x", sf::Color::Red );
	g.DrawText( vecAxisY  + Vector3f(0, +5, 0),		"y", sf::Color::Green );
	g.DrawText( vecAxisZ  + Vector3f(0, 0, +5),		"z", sf::Color::Blue );
}