/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		08/11/2012
 */





//=================================================================
//	Inlude
//---------------------------------------
#include <cmath>





//=================================================================
//	TransformUtils::DegToRad() : converts from degrees to radians
//---------------------------------------
template< typename T>
double TransformUtils::DegToRad( T deg )
{
	const double PI = 3.141592653589793238462643383279502884;
	return deg * PI / 180.0;
}





//=================================================================
//	TransformUtils::RadToDeg() : converts from radians to degrees
//---------------------------------------
template< typename T>
T TransformUtils::RadToDeg( double rad )
{
	const double PI = 3.141592653589793238462643383279502884;
	return rad * 180.0 / PI;
}





//=================================================================
//	TransformUtils::SetIdentity() : sets the matrix to identity
//---------------------------------------
template< int I, typename T>
void TransformUtils::SetIdentity(Matrix<I,I, T> &theMatrix)
{
	for( int i=0; i< I; i++ )
	{
		for( int j=0; j< I; j++ )
		{
			if( i==j )
			{
				theMatrix(i, j) = 1;
			}
			else
			{
				theMatrix(i, j) = 0;
			}
		}
	}
}





//=================================================================
//	TransformUtils::SetTranslation() : sets the matrix to shift
//---------------------------------------
template< typename T >
void TransformUtils::SetTranslation(Matrix<4,4, T> &theMatrix, T x, T y, T z)
{
	SetIdentity( theMatrix );
	theMatrix(0,3) = x;
	theMatrix(1,3) = y;
	theMatrix(2,3) = z;
}





//=================================================================
//	TransformUtils::SetScale() : sets the matrix to scale
//---------------------------------------
template< typename T >
void TransformUtils::SetScale(Matrix<4,4, T> &theMatrix, T sx, T sy, T sz)
{
	SetIdentity( theMatrix );
	theMatrix(0, 0) = sx;
	theMatrix(1, 1) = sy;
	theMatrix(2, 2) = sz;
}





//=================================================================
//	TransformUtils::SetRotationX() : sets rotation around the X axis
//---------------------------------------
template< typename T >
void TransformUtils::SetRotationX(Matrix<4,4, T> &theMatrix, T rx)
{
	double radRx = DegToRad( rx );
	SetIdentity( theMatrix );
	theMatrix(1, 1) = (T)  cos(radRx);
	theMatrix(1, 2) = (T) -sin(radRx);
	theMatrix(2, 1) = (T)  sin(radRx);
	theMatrix(2, 2) = (T)  cos(radRx);
}





//=================================================================
//	TransformUtils::SetRotationY() : sets rotation around the Y axis
//---------------------------------------
template< typename T >
void TransformUtils::SetRotationY(Matrix<4,4, T> &theMatrix, T ry)
{
	double radRy = DegToRad( ry );
	SetIdentity( theMatrix );

	theMatrix(2, 2) = (T)  cos(radRy);
	theMatrix(2, 0) = (T) -sin(radRy);
	theMatrix(0, 2) = (T)  sin(radRy);
	theMatrix(0, 0) = (T)  cos(radRy);
}





//=================================================================
//	TransformUtils::SetRotationZ() : sets rotation around the Z axis
//---------------------------------------
template< typename T >
void TransformUtils::SetRotationZ(Matrix<4,4, T> &theMatrix, T rz)
{
	double radRz = DegToRad( rz );
	SetIdentity( theMatrix );

	theMatrix(0, 0) = (T)  cos(radRz);
	theMatrix(0, 1) = (T) -sin(radRz);
	theMatrix(1, 0) = (T)  sin(radRz);
	theMatrix(1, 1) = (T)  cos(radRz);
}





//=================================================================
//	TransformUtils::AddTranslation() : adds shift to the matrix
//---------------------------------------
template< typename T >
void TransformUtils::AddTranslation(Matrix<4,4, T> &theMatrix, T x, T y, T z)
{
	Matrix<4, 4, T> tempMatrix;
	SetTranslation( tempMatrix, x, y, z );

	theMatrix = theMatrix * tempMatrix;
}




//=================================================================
//	TransformUtils::AddRotationX() : adds rotation around the X axis
//---------------------------------------
template< typename T >
void TransformUtils::AddRotationX(Matrix<4,4, T> &theMatrix, T rx)
{
	Matrix<4, 4, T> tempMatrix;
	SetRotationX( tempMatrix, rx );

	theMatrix = theMatrix * tempMatrix;
}





//=================================================================
//	TransformUtils::AddRotationY() : adds rotation around the Y axis
//---------------------------------------
template< typename T >
void TransformUtils::AddRotationY(Matrix<4,4, T> &theMatrix, T ry)
{
	Matrix<4, 4, T> tempMatrix;
	SetRotationY( tempMatrix, ry );

	theMatrix = theMatrix * tempMatrix;
}





//=================================================================
//	TransformUtils::AddRotationZ() : adds rotation around the Z axis
//---------------------------------------
template< typename T >
void TransformUtils::AddRotationZ(Matrix<4,4, T> &theMatrix, T rz)
{
	Matrix<4, 4, T> tempMatrix;
	SetRotationZ( tempMatrix, rz );

	theMatrix = theMatrix * tempMatrix;
}





//=================================================================
//	TransformUtils::SetLookAt() : sets a camera view matrix
//---------------------------------------
template< typename T >
void TransformUtils::SetLookAt(Matrix<4,4, T> &theMatrix, Vector<3, T> eye, Vector<3, T> lookAt, Vector<3, T> up, bool leftHanded )
{
	Vector<3, T> zaxis = (lookAt - eye).Unit() * (leftHanded? 1:-1);
	Vector<3, T> xaxis  = up.Cross( zaxis ).Unit();
	Vector<3, T> yaxis  = xaxis.Cross( zaxis ).Unit();

	theMatrix(0,0) = xaxis.x;
	theMatrix(0,1) = xaxis.y;
	theMatrix(0,2) = xaxis.z;
	theMatrix(0,3) = 0;

	theMatrix(1,0) = yaxis.x;
	theMatrix(1,1) = yaxis.y;
	theMatrix(1,2) = yaxis.z;
	theMatrix(1,3) = 0;

	theMatrix(2,0) = zaxis.x;
	theMatrix(2,1) = zaxis.y;
	theMatrix(2,2) = zaxis.z;
	theMatrix(2,3) = 0;

	theMatrix(3,0) = 0;
	theMatrix(3,1) = 0;
	theMatrix(3,2) = 0;
	theMatrix(3,3) = 1;


	Matrix<4,4, T> posMat;
	SetTranslation( posMat, -eye.x, -eye.y, -eye.z );

	theMatrix = posMat * theMatrix;
}