/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		06/11/2012
 */

#ifndef __GRAPHICS_3D_H__
#define __GRAPHICS_3D_H__

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Matrix.h"
#include "Vector.h"


class Graphics3D
{
public:
							Graphics3D();
							Graphics3D( sf::RenderTarget &theTarget);

	void					SetRenderTarget( sf::RenderTarget &theTarget );
	sf::RenderTarget *		GetRenderTarget();

	void					SetViewTransform( const Matrix4f &theViewTransform );
	Matrix4f &				GetViewTransform();

	void					DrawLine( Vector3f p1,  Vector3f p2, sf::Color color = sf::Color::White );
	void					DrawText( Vector3f pos, const char * text, sf::Color color = sf::Color::White );

protected:

private:
	Vector3f				TransformPoint( const Vector3f &p );

private:
	sf::RenderTarget	  * mRenderTarget;
	Matrix4f				mViewTransform;
	
};


#endif