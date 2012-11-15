/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		15/11/2012
 */

#ifndef __SHEAR_TRANSFORM_H__
#define __SHEAR_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "TransformOperation.h"





//=================================================================
//	Class PerspectiveProjTransform
//---------------------------------------
class ShearTransform :	public TransformOperation 
{
public:
	Vector3f				surfNormal;
	Vector3f				shearDir;

	enum { TRANSFORM_TYPE = 'sher' };

public:

							ShearTransform(	const Vector3f &theNormal = Vector3f(),
											const Vector3f &theShearDir = Vector3f()) :
									surfNormal( theNormal.Unit() ),
									shearDir( theShearDir )	{}

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		//p' = p + (p.n)v
		return point + shearDir * surfNormal.Dot( point );
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Shear n=(" 
			<< surfNormal.x << ", " << surfNormal.y << ", " << surfNormal.z 
			<< ")  v=("
			<< shearDir.x << ", " << shearDir.y << ", " << shearDir.z
			<< ")";
	}


	virtual Matrix4f		BuildMatrix()
	{
		Matrix4f m;

		Vector3f &n = surfNormal;
		Vector3f &v = shearDir;
		
		// TODO
		m(0,0) = 1 + v.x * n.x;
		m(0,1) =	 v.x * n.y;
		m(0,2) =	 v.x * n.z;
		m(0,3) = 0;

		m(1,0) =	 v.y * n.x;
		m(1,1) = 1 + v.y * n.y;
		m(1,2) =	 v.y * n.z;
		m(1,3) = 0;

		m(2,0) =	 v.z * n.x;
		m(2,1) =	 v.z * n.y;
		m(2,2) = 1 + v.z * n.z;
		m(2,3) = 0;

		m(3,0) = 0;
		m(3,1) = 0;
		m(3,2) = 0;
		m(3,3) = 1;

		return m;
	}
};





#endif