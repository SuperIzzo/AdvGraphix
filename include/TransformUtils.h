/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		08/11/2012
 */

#ifndef __TRANSFORMUTILS_H__
#define __TRANSFORMUTILS_H__





//=================================================================
//	Inlude
//---------------------------------------
#include "Vector.h"
#include "Matrix.h"





//=================================================================
//	Class TransformUtils
//---------------------------------------
class TransformUtils
{
public:
	template< typename T >
	static void				Rotate(Vector<3,T> &theVector, Vector<3, T> axis, T alpha);


	template< int I, typename T>
	static void				SetIdentity(Matrix<I,I, T> &theMatrix);

	template< typename T >
	static void				SetTranslation(Matrix<4,4, T> &theMatrix, T x, T y, T z);

	template< typename T >
	static void				SetScale(Matrix<4,4, T> &theMatrix, T sx, T sy, T sz);

	template< typename T >
	static void				SetRotationX(Matrix<4,4, T> &theMatrix, T rx);

	template< typename T >
	static void				SetRotationY(Matrix<4,4, T> &theMatrix, T ry);

	template< typename T >
	static void				SetRotationZ(Matrix<4,4, T> &theMatrix, T rz);

	template< typename T >
	static void				AddTranslation(Matrix<4,4, T> &theMatrix, T x, T y, T z);

	template< typename T >
	static void				AddRotationX(Matrix<4,4, T> &theMatrix, T rx);

	template< typename T >
	static void				AddRotationY(Matrix<4,4, T> &theMatrix, T ry);

	template< typename T >
	static void				AddRotationZ(Matrix<4,4, T> &theMatrix, T rz);

	template< typename T >
	static void				AddScale(Matrix<4,4, T> &theMatrix, T sx, T sy, T sz);

	template< typename T >
	static void				SetLookAt( Matrix<4,4, T> &theMatrix, Vector<3, T> eye, Vector<3, T> look, Vector<3, T> up, bool leftHanded = true );

private:
	template< typename T >
	static inline double	DegToRad( T deg );

	template< typename T >
	static inline T			RadToDeg( double rad );
};





//=================================================================
//	Inline implementation
//---------------------------------------
#include "TransformUtils.inl"





#endif