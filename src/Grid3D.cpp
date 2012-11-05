#include "Grid3D.h"

#include <SFML\Graphics\RenderTarget.hpp>





//=================================================================
//	Grid3D::Grid3D
//---------------------------------------
Grid3D::Grid3D() 
{
	mLines.setPrimitiveType( sf::PrimitiveType::Lines );
	mLines.resize(2);
	mLines[0] = sf::Vertex( sf::Vector2f(0,0),		sf::Color::White );
	mLines[1] = sf::Vertex( sf::Vector2f(100,100),	sf::Color::White );
}





//=================================================================
//	Grid3D::draw : Implement our sf::Drawable drawing routine
//---------------------------------------
void Grid3D::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw( mLines, states );
}