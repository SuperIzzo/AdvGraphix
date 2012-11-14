/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		14/11/2012
 */

#ifndef __PARALLEL_PROJ_TRANSFORM_H__
#define __PARALLEL_PROJ_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "TransformOperation.h"





//=================================================================
//	Class ParallelProjTransform
//---------------------------------------
class ParallelProjTransform :	public TransformOperation 
{
public:
	Vector3f				surfNormal;
	Vector3f				viewDir;

	enum { TRANSFORM_TYPE = 'papr' };

public:

							ParallelProjTransform(	const Vector3f &theNormal = Vector3f(),
													const Vector3f &theViewDir = Vector3f()) :
									surfNormal( theNormal.Unit() ),
									viewDir( theViewDir.Unit() )	{}

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		// p'= p - c(p.n)/(c.n)
		return point - viewDir * surfNormal.Dot( point ) / surfNormal.Dot( viewDir );
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Parallel Projection n=(" 
			<< surfNormal.x << ", " << surfNormal.y << ", " << surfNormal.z 
			<< ")  c=("
			<< viewDir.x << ", " << viewDir.y << ", " << viewDir.z
			<< ")";
	}


	virtual Matrix4f		BuildMatrix()
	{
		Matrix4f m;

		Vector3f &n = surfNormal;
		Vector3f &c = viewDir;
		float inv_n_dot_c = 1/n.Dot( c );

		m(0,0) = 1 - n.x * c.x * inv_n_dot_c;
		m(0,1) =   - n.y * c.x * inv_n_dot_c;
		m(0,2) =   - n.z * c.x * inv_n_dot_c;
		m(0,3) = 0;

		m(1,0) =   - n.x * c.y * inv_n_dot_c;
		m(1,1) = 1 - n.y * c.y * inv_n_dot_c;
		m(1,2) =   - n.z * c.y * inv_n_dot_c;
		m(1,3) = 0;

		m(2,0) =   - n.x * c.z * inv_n_dot_c;
		m(2,1) =   - n.y * c.z * inv_n_dot_c;
		m(2,2) = 1 - n.z * c.z * inv_n_dot_c;
		m(2,3) = 0;

		m(3,0) = 0;
		m(3,1) = 0;
		m(3,2) = 0;
		m(3,3) = 1;

		return m;
	}
};





#endif