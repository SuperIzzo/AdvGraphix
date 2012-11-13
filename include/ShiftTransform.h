/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		13/11/2012
 */

#ifndef __SHIFT_TRANSFORM_H__
#define __SHIFT_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "TransformOperation.h"





//=================================================================
//	Class ShiftTransform
//---------------------------------------
class ShiftTransform :	public TransformOperation 
{
public:
	Vector3f				shift;

public:
							ShiftTransform(const Vector3f &theShift = Vector3f()) :
								shift( theShift ) {}

	virtual Vector3f		Transform(const Vector3f &point)
	{
		return point + shift;
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Shift t=(" << shift.x << ", " << shift.y << ", " << shift.z << ")";
	}
};





#endif