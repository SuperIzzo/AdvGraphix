/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		13/11/2012
 */

#ifndef __SCALE_TRANSFORM_H__
#define __SCALE_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "TransformOperation.h"





//=================================================================
//	Class ScaleTransform
//---------------------------------------
class ScaleTransform :	public TransformOperation
{
public:
	float					alpha;
	Vector3f				direction;

	enum { TRANSFORM_TYPE = 'scal' };

public:
							ScaleTransform(const Vector3f &dir, float alp) :
								direction(dir),
								alpha(alp) {}

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		// p' = p + (a-1)*s*(s.p)
		return point + direction * (alpha - 1.0f) * direction.Dot(point);
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Scale s=(" << direction.x << ", " << direction.y << ", " << direction.z << ")  a=" << alpha;
	}


	virtual Matrix4f		BuildMatrix()
	{
		Matrix4f m;
		Vector3f &s = direction;

		m(0,0) = 1 + (alpha - 1) * s.x*s.x;
		m(0,1) = (alpha - 1) * s.x*s.y;
		m(0,2) = (alpha - 1) * s.x*s.z;
		m(0,3) = 0;

		m(1,0) = (alpha - 1) * s.x*s.y;
		m(1,1) = 1 + (alpha - 1) * s.y*s.y;
		m(1,2) = (alpha - 1) * s.y*s.z;
		m(1,3) = 0;

		m(2,0) = (alpha - 1) * s.x*s.z;
		m(2,1) = (alpha - 1) * s.y*s.z;
		m(2,2) = 1 + (alpha - 1) * s.z*s.z;
		m(2,3) = 0;

		m(3,0) = 0;
		m(3,1) = 0;
		m(3,2) = 0;
		m(3,3) = 1;

		return m;
	}
};





#endif