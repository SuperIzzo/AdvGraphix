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
#include "Matrix.h"





//=================================================================
//	Class TransformOperation
//---------------------------------------
class TransformOperation
{
public:
	virtual Vector3f		Transform(const Vector3f &point) = 0;
	virtual	void			Display(std::ostream &os) = 0;
	virtual Matrix4f		BuildMatrix() = 0;
	virtual int				GetType() = 0;

	inline  Vector3f		operator()(const Vector3f &point)
	{
		return Transform(point);
	}
};





#endif