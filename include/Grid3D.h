/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		05/11/2012
 */
#ifndef __GRID3D_H__
#define __GRID3D_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "Graphics3D.h"



//=================================================================
//	Class Grid3D
//---------------------------------------
class Grid3D
{
public:
						Grid3D();

public:
	void				Draw( Graphics3D &g ) const;

	Vector3f &			Position();
	Vector3f &			Size();
	Vector3f &			Spacing();

private:
	Vector3f			mGridPosition;

	Vector3f			mGridSize;
	Vector3f			mSquareSpacing;
};





#endif