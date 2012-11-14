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
#include "TransformUtils.h"





//=================================================================
//	Class ShiftTransform
//---------------------------------------
class ShiftTransform :	public TransformOperation 
{
public:
	Vector3f				shift;

	enum { TRANSFORM_TYPE = 'shft' };

public:
							ShiftTransform(const Vector3f &theShift = Vector3f()) :
								shift( theShift ) {}
								

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		return point + shift;
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Shift t=(" << shift.x << ", " << shift.y << ", " << shift.z << ")";
	}


	virtual Matrix4f		BuildMatrix()
	{
		Matrix4f m;
		TransformUtils::SetIdentity(m);

		m(0,3) = shift.x;
		m(1,3) = shift.y;
		m(2,3) = shift.z;

		return m;
	}
};





#endif