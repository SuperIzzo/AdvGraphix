/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		15/11/2012
 */

#ifndef __PERSPECTIVE_PROJ_TRANSFORM_H__
#define __PERSPECTIVE_PROJ_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "TransformOperation.h"





//=================================================================
//	Class PerspectiveProjTransform
//---------------------------------------
class PerspectiveProjTransform :	public TransformOperation 
{
public:
	Vector3f				surfNormal;
	Vector3f				focalPoint;

	enum { TRANSFORM_TYPE = 'pepr' };

public:

							PerspectiveProjTransform(	const Vector3f &theNormal = Vector3f(),
														const Vector3f &theFocalPoint = Vector3f()) :
									surfNormal( theNormal.Unit() ),
									focalPoint( theFocalPoint )	{}

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		//p' = p - (p.n)(p-v)/(n.(p-v))
		Vector3f theViewDir = point - focalPoint;
		return point - theViewDir * surfNormal.Dot( point ) / surfNormal.Dot( theViewDir );
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Perspective Projection n=(" 
			<< surfNormal.x << ", " << surfNormal.y << ", " << surfNormal.z 
			<< ")  v=("
			<< focalPoint.x << ", " << focalPoint.y << ", " << focalPoint.z
			<< ")";
	}


	virtual Matrix4f		BuildMatrix()
	{
		Matrix4f m;

		Vector3f &n = surfNormal;
		Vector3f &v = focalPoint;
		
		// TODO

		return m;
	}
};





#endif