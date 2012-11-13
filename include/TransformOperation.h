/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		13/11/2012
 */

#ifndef __TRANSFORM_OPERATION_H__
#define __TRANSFORM_OPERATION_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "Vector.h"





//=================================================================
//	Class TransformOperation
//---------------------------------------
class TransformOperation
{
public:
	virtual Vector3f		Transform(const Vector3f &point) = 0;

	inline  Vector3f		operator()(const Vector3f &point)
	{
		return Transform(point);
	}
};





#endif