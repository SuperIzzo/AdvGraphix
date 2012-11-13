//=================================================================
//	Inlude
//---------------------------------------
#include "Camera.h"
#include "TransformUtils.h"





//=================================================================
//	Camera::Camera
//---------------------------------------
Camera::Camera(Matrix4f * aViewMat) :
	mViewMatrix(aViewMat) ,
	mZoom( 1 )
{
}





//=================================================================
//	Camera::Position : the camera position
//---------------------------------------
Vector3f& Camera::Position()
{
	return mPosition;
}





//=================================================================
//	Camera::Target : the camera target
//---------------------------------------
Vector3f& Camera::Target()
{
	return mTarget;
}





//=================================================================
//	Camera::UpVector : the camera up vector
//---------------------------------------
Vector3f& Camera::UpVector()
{
	return mUp;
}





//=================================================================
//	Camera::Zoom : the camera zoom
//---------------------------------------
float& Camera::Zoom()
{
	return mZoom;
}





//=================================================================
//	Camera::GetViewMatrix : the view camera associated matrix
//---------------------------------------
Matrix4f * Camera::GetViewMatrix()
{
	return mViewMatrix;
}





//=================================================================
//	Camera::SetViewMatrix : associate the camera with a matrix
//---------------------------------------
void Camera::SetViewMatrix(Matrix4f *theMat)
{
	mViewMatrix = theMat;
}





//=================================================================
//	Camera::Update : updates the view matrix
//---------------------------------------
void Camera::Update()
{
	if( mViewMatrix )
	{
		TransformUtils::SetLookAt( *mViewMatrix, mPosition, mTarget, mUp );
		TransformUtils::AddScale( *mViewMatrix, mZoom, mZoom, mZoom );
	}
}