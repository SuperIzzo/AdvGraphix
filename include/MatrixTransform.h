/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		14/11/2012
 */

#ifndef __MATRIX_TRANSFORM_H__
#define __MATRIX_TRANSFORM_H__





//=================================================================
//	Inlude
//---------------------------------------
#include <string>
#include <vector>
#include "TransformOperation.h"
#include "Matrix.h"





//=================================================================
//	Class MatrixTransform
//---------------------------------------
class MatrixTransform :	public TransformOperation 
{
public:
	Matrix4f						matrix;
	std::vector<std::string>		operations;

	enum { TRANSFORM_TYPE = 'mtrx' };

public:
	
							MatrixTransform(Matrix4f &theMat, std::string caption = "") :
								matrix( theMat )
							{
								operations.push_back( caption );
							}

	virtual int				GetType()
	{
		return TRANSFORM_TYPE;
	}


	virtual Vector3f		Transform(const Vector3f &point)
	{
		Vector3f theResult;
		Vector4f homogenPoint;

		homogenPoint.x = point.x;
		homogenPoint.y = point.y;
		homogenPoint.z = point.z;
		homogenPoint.w = 1.0f;

		homogenPoint = matrix * homogenPoint;

		theResult.x = homogenPoint.x / homogenPoint.w;
		theResult.y = homogenPoint.y / homogenPoint.w;
		theResult.z = homogenPoint.z / homogenPoint.w;

		return theResult;
	}


	virtual	void			Display(std::ostream &os)
	{
		os << "Matrix";

		for( int i = 0; i< operations.size(); i++ )
		{
			os << "\n    * " << operations[i];
		}
	}


	virtual Matrix4f		BuildMatrix()
	{
		return matrix;
	}
};





#endif