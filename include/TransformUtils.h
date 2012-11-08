/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		08/11/2012
 */

#ifndef __TRANSFORMUTILS_H__
#define __TRANSFORMUTILS_H__

#include "Vector.h"
#include "Matrix.h"


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
};



#include "TransformUtils.inl"

#endif