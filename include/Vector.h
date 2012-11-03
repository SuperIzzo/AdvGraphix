/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__


#include "VectorData.h"


template< int D, typename T >

struct Vector	: public VectorData<D, T>
{
public:
	typedef	T				CoordType;
	static const int		DIMENSIONS = D;

public:
							Vector();
							Vector(CoordType aX);
							Vector(CoordType aX, CoordType aY);
							Vector(CoordType aX, CoordType aY, CoordType aZ);
							Vector(CoordType aX, CoordType aY, CoordType aZ, CoordType aW);
							

	CoordType				Dot(const Vector<D, T>	 &other);
	CoordType				Length();

	Vector<D, T>			Unit();
	Vector<3, T>			Cross(const Vector<3, T> &other);

	Vector<D, T>			operator+(const Vector<D, T>	&other);
	Vector<D, T>			operator-(const Vector<D, T>	&other);
	Vector<D, T>			operator*(T scalar);
	Vector<D, T>			operator/(T scalar);
	CoordType&				operator[] (size_t index);


};



// Float vectors
typedef Vector<1, float> Vector1f;
typedef Vector<2, float> Vector2f;
typedef Vector<3, float> Vector3f;
typedef Vector<4, float> Vector4f;

// Double vectors
typedef Vector<1, double> Vector1d;
typedef Vector<2, double> Vector2d;
typedef Vector<3, double> Vector3d;
typedef Vector<4, double> Vector4d;

// Int vectors
typedef Vector<1, int> Vector1i;
typedef Vector<2, int> Vector2i;
typedef Vector<3, int> Vector3i;
typedef Vector<4, int> Vector4i;


// The implementation
#include "Vector.inl"

#endif