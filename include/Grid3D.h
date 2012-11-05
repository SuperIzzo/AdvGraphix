/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		05/11/2012
 */

#ifndef __GRID3D_H__
#define __GRID3D_H__


#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\VertexArray.hpp>



//=================================================================
//	Class Grid3D
//---------------------------------------
class Grid3D : public sf::Drawable
{
public:
						Grid3D();

protected:
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::VertexArray		mLines;
};





#endif