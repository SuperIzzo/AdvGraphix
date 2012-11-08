/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		06/11/2012
 */

#ifndef __GRAPHICS_3D_H__
#define __GRAPHICS_3D_H__

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Matrix.h"
#include "Vector.h"


class Graphics3D : public sf::Drawable
{
public:
	void				Line( Vector3f p1,  Vector3f p2, sf::Color color = sf::Color::White );

protected:
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Matrix4f			mViewTransform;
	
}


#endif