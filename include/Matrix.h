/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		06/11/2012
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__


#include "Vector.h"


template< int ROW, int COL, typename T >
class Matrix
{
public:
							//Matrix();
	T&						operator()(size_t r, size_t c);
	Matrix<ROW, COL,T>		operator+(const Matrix<ROW,COL,T> &other);

	template<size_t X>
	Matrix<ROW,X,T>			operator*(const Matrix<COL,X,T> &other);
	Vector<ROW,T>			operator*(const Vector<COL,T> &vector);

private:
	T						mElem[COL][ROW];
};




typedef Matrix<3,3, float>		Matrix3f;
typedef Matrix<4,4, float>		Matrix4f;


#include "Matrix.inl"


#endif