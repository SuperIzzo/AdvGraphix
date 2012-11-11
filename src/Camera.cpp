#include "Camera.h"
#include "TransformUtils.h"



Camera::Camera(Matrix4f * aViewMat) :
	mViewMatrix(aViewMat)
{
}





const Vector3f& Camera::GetPosition()
{
	return mPosition;
}





const Vector3f& Camera::GetTarget()
{
	return mTarget;
}





const Vector3f& Camera::GetUpVector()
{
	return mUp;
}





Matrix4f * Camera::GetViewMatrix()
{
	return mViewMatrix;
}





void Camera::SetPosition(const Vector3f &pos)
{
	mPosition = pos;
}





void Camera::SetTarget(const Vector3f &target)
{
	mTarget = target;
}





void Camera::SetUpVector(const Vector3f &upVec)
{
	mUp = upVec;
}





void Camera::SetViewMatrix(Matrix4f *theMat)
{
	mViewMatrix = theMat;
}





void Camera::Update()
{
	if( mViewMatrix )
	{
		TransformUtils::SetLookAt( *mViewMatrix, mPosition, mTarget, mUp );
	}
}