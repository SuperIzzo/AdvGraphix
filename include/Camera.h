/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		11/11/2012
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "Vector.h"
#include "Matrix.h"





//=================================================================
//	Class Camera
//---------------------------------------
class Camera
{
public:
							Camera(Matrix4f * aViewMat = 0);

	Vector3f &				Position();
	Vector3f &				Target();
	Vector3f &				UpVector();

	float &					Zoom();

	void					SetViewMatrix(Matrix4f *viewMat);
	Matrix4f *				GetViewMatrix();

	void					Update();

private:
	Matrix4f			  *	mViewMatrix;
	Vector3f				mPosition;
	Vector3f				mTarget;
	Vector3f				mUp;

	float					mZoom;
};





#endif