/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		14/11/2012
 */

#ifndef __REFLECT_TRANSFORM_H__
#define __REFLECT_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "TransformOperation.h"





//=================================================================
//	Class ReflectTransform
//---------------------------------------
class ReflectTransform :	public TransformOperation 
{
public:
	Vector3f				surfNormal;

	enum { TRANSFORM_TYPE = 'refl' };

public:
							ReflectTransform(const Vector3f &theNormal = Vector3f()) :
								surfNormal( theNormal.Unit() ) {}

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		// p' = p - 2n(p.n)
		return point - surfNormal * 2 * surfNormal.Dot( point );
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Reflect n=(" << surfNormal.x << ", " << surfNormal.y << ", " << surfNormal.z << ")";
	}


	virtual Matrix4f		BuildMatrix()
	{
		Matrix4f m;
		Vector3f &n = surfNormal;

		m(0,0) = 1 - 2*n.x*n.x;
		m(0,1) = - 2*n.x*n.y;
		m(0,2) = - 2*n.x*n.z;
		m(0,3) = 0;

		m(1,0) = -2*n.x*n.y;
		m(1,1) = 1 -2*n.y*n.y;
		m(1,2) = -2*n.y*n.z;
		m(1,3) = 0;

		m(2,0) = -2*n.x*n.z;
		m(2,1) = -2*n.y*n.z;
		m(2,2) = 1 -2*n.z*n.z;
		m(2,3) = 0;

		m(3,0) = 0;
		m(3,1) = 0;
		m(3,2) = 0;
		m(3,3) = 1;

		return m;
	}
};





#endif