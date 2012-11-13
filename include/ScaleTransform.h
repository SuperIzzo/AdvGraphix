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

public:
							ScaleTransform(const Vector3f &dir, float alp) :
								direction(dir),
								alpha(alp) {}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		// p0 = p + (a-1)*s*(s.p)
		return point + direction * (alpha - 1.0f) * direction.Dot(point);
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Scale s=(" << direction.x << ", " << direction.y << ", " << direction.z << ")  a=" << alpha;
	}
};





#endif