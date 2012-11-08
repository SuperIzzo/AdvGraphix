#include "Graphics3D.h"

#include <SFML/Graphics/VertexArray.hpp>

#include "TransformUtils.h"


Graphics3D::Graphics3D()
	: mRenderTarget(0)
{
	TransformUtils::SetIdentity( mViewTransform );
}





Graphics3D::Graphics3D( sf::RenderTarget &theTarget )
	: mRenderTarget(&theTarget)
{

}





void Graphics3D::SetRenderTarget( sf::RenderTarget &theTarget )
{
	mRenderTarget = &theTarget;
}





sf::RenderTarget * Graphics3D::GetRenderTarget()
{
	return mRenderTarget;
}





void Graphics3D::DrawLine( Vector3f p1,  Vector3f p2, sf::Color color )
{
	if( mRenderTarget )
	{
		Vector3f outputP1 = TransformPoint( p1 );
		Vector3f outputP2 = TransformPoint( p2 );

		sf::VertexArray theLine;
		theLine.setPrimitiveType( sf::PrimitiveType::Lines );
		theLine.resize(2);
		theLine[0] = sf::Vertex( sf::Vector2f(p1.x, p1.y),	color );
		theLine[1] = sf::Vertex( sf::Vector2f(p2.x, p2.y),	color );

		mRenderTarget->draw( theLine );
	}
}





Vector3f Graphics3D::TransformPoint( const Vector3f &p )
{
	Vector3f theResult;
	Vector4f hp;

	hp.x = p.x;
	hp.y = p.y;
	hp.z = p.z;
	hp.w = 1.0f;

	mViewTransform * hp;

	theResult.x = hp.x / hp.w;
	theResult.y = hp.y / hp.w;
	theResult.z = hp.z / hp.w;

	return theResult;theResult.x = hp.x / hp.w;
}