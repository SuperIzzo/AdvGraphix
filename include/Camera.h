/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		11/11/2012
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__


#include "Vector.h"
#include "Matrix.h"


class Camera
{
public:
							Camera(Matrix4f * aViewMat = 0);

	void					SetPosition(const Vector3f &pos);
	void					SetTarget(const Vector3f &target);
	void					SetUpVector(const Vector3f &upVec);
	void					SetViewMatrix(Matrix4f *viewMat);

	const Vector3f &		GetPosition();
	const Vector3f &		GetTarget();
	const Vector3f &		GetUpVector();
	Matrix4f *				GetViewMatrix();

	void					Update();

private:
	Matrix4f			  *	mViewMatrix;
	Vector3f				mPosition;
	Vector3f				mTarget;
	Vector3f				mUp;
};



#endif