//=================================================================
//	Inlude
//---------------------------------------
#include "Graphics3D.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Text.hpp>

#include "TransformUtils.h"





//=================================================================
//	Graphics3D::Graphics3D
//---------------------------------------
Graphics3D::Graphics3D()
	: mRenderTarget(0)
{
	TransformUtils::SetIdentity( mViewTransform );
}





//=================================================================
//	Graphics3D::Graphics3D
//---------------------------------------
Graphics3D::Graphics3D( sf::RenderTarget &theTarget )
	: mRenderTarget(&theTarget)
{

}





//=================================================================
//	Graphics3D::SetRenderTarget : sets a 2D SFML rendering target
//---------------------------------------
void Graphics3D::SetRenderTarget( sf::RenderTarget &theTarget )
{
	mRenderTarget = &theTarget;
}





//=================================================================
//	Graphics3D::SetRenderTarget : returns the 2D SFML rendering target
//---------------------------------------
sf::RenderTarget * Graphics3D::GetRenderTarget()
{
	return mRenderTarget;
}





//=================================================================
//	Graphics3D::ViewTransform : the view transform matrix
//---------------------------------------
Matrix4f & Graphics3D::ViewTransform()
{
	return mViewTransform;
}





//=================================================================
//	Graphics3D::DrawLine : draws a 3D line
//---------------------------------------
void Graphics3D::DrawLine( Vector3f p1,  Vector3f p2, sf::Color color )
{
	if( mRenderTarget )
	{
		Vector3f outputP1 = TransformPoint( p1 );
		Vector3f outputP2 = TransformPoint( p2 );

		sf::VertexArray theLine;
		theLine.setPrimitiveType( sf::Lines );

		theLine.resize(2);
		theLine[0] = sf::Vertex( sf::Vector2f(outputP1.x, outputP1.y),	color );
		theLine[1] = sf::Vertex( sf::Vector2f(outputP2.x, outputP2.y),	color );

		// NOTE: For now we ignore the z voordinate
		// It could however be used with a depth buffer 

		mRenderTarget->draw( theLine );
	}
}





//=================================================================
//	Graphics3D::DrawText : draws text at a 3D point
//---------------------------------------
void Graphics3D::DrawText( Vector3f pos, const char * text, sf::Color color )
{
	if( mRenderTarget )
	{
		Vector3f outputPos = TransformPoint( pos );

		sf::Text textObj( text );
		textObj.setColor( color );

		textObj.setPosition( outputPos.x, outputPos.y );

		mRenderTarget->draw( textObj );
	}
}





//=================================================================
//	Graphics3D::TransformPoint : transforms a vector according to the view
//---------------------------------------
Vector3f Graphics3D::TransformPoint( const Vector3f &p )
{
	Vector3f theResult;
	Vector4f hp;

	hp.x = p.x;
	hp.y = p.y;
	hp.z = p.z;
	hp.w = 1.0f;

	hp = mViewTransform * hp;

	theResult.x = hp.x / hp.w;
	theResult.y = hp.y / hp.w;
	theResult.z = hp.z / hp.w;

	return theResult;
}