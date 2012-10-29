#ifndef __VECTOR_H__
#define __VECTOR_H__

/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#include "VectorCommon.h"





// General vectors case - vector in the most common sense
template< int dimensions, typename Type >
class Vector :public VectorCommon<dimensions, Type>
{
};





// One dimensional vector
template< typename Type >
class Vector<1, Type>	:	public VectorCommon<1, Type>
{
public:
						Vector();
						Vector(Type aX);
};



template< typename Type >
class Vector<2, Type>	:	public VectorCommon<2, Type>
{
public:
						Vector();
						Vector(Type aX, Type aY);
};



template< typename Type >
class Vector<3, Type>	:	public VectorCommon<3, Type>
{
public:
						Vector();
						Vector(Type aX, Type aY, Type aZ);

	Vector<3, Type>		Cross(const Vector<3, Type> &other);
};



template< typename Type >
class Vector<4, Type>	:	public VectorCommon<4, Type>
{
public:
						Vector();
						Vector(Type aX, Type aY, Type aZ, Type aW);
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