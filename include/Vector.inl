/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTOR_INL__
#define __VECTOR_INL__



#define STATIC_ASSERT( cond, desc )		int desc[cond]; (void) desc;


//=================================================================
//	Vector::Vector
//---------------------------------------
template< int D, typename T>

Vector<D, T>::Vector()
{
}





//=================================================================
//	Vector::Vector(x)
//---------------------------------------
template< int D, typename T>

Vector<D, T>::Vector(T aX)
	: VectorData(aX)
{
}





//=================================================================
//	Vector::Vector(x,y)
//---------------------------------------
template< int D, typename T>

Vector<D, T>::Vector(T aX, T aY)
	: VectorData(aX, aY)
{
}





//=================================================================
//	Vector::Vector(x,y,z)
//---------------------------------------
template< int D, typename T>

Vector<D, T>::Vector(T aX, T aY, T aZ)
	: VectorData(aX, aY, aZ)
{
}





//=================================================================
//	Vector::Vector(x,y,z,w)
//---------------------------------------
template< int D, typename T>

Vector<D, T>::Vector(T aX, T aY, T aZ, T aW)
	: VectorData(aX, aY, aZ, aW)
{
}





//=================================================================
//	Vector::Dot : Returns the dot product between two vectors
//---------------------------------------
template< int D, typename T>

T Vector<D, T>::Dot(const Vector<D, T> &other)
{
	T theResult = 0;

	for( int i=0; i<D; i++ )
	{
		theResult += this->coords[i] * other.coords[i];
	}

	return theResult;
}





//=================================================================
//	Vector::Length : Returns the length of a vector
//---------------------------------------
template< int D, typename T>

T Vector<D, T>::Length()
{
	T theResult = 0;

	for( int i=0; i<D; i++ )
	{
		theResult += coords[i] * coords[i];
	}

	return (T) sqrt(theResult);
}





//=================================================================
//	Vector::operator+ : Returns the sum of two vectors
//---------------------------------------
template< int D, typename T>
Vector<D, T>	Vector<D, T>::operator+(const Vector<D, T>	&other)
{
	Vector<D, T> theResult;

	for( int i=0; i< D; i++ )
	{
		theResult.coords[i] = this->coords[i] + other.coords[i];
	}

	return theResult;
}





//=================================================================
//	Vector::Cross : Returns the cross product of two 3D vectors
//---------------------------------------
template< int D, typename T>
Vector<3, T>	Vector<D, T>::Cross(const Vector<3, T>	&other)
{
	Vector<3, T> theResult;

	STATIC_ASSERT( D==3, vector_cross_produc_is_only_defined_for_3D_vectors );

	theResult.x = (this->y * other.z) - (this->z * other.y);
	theResult.y = (this->z * other.x) - (this->x * other.z);
	theResult.z = (this->x * other.y) - (this->y * other.x);

	return theResult;
}





//=================================================================
//	Vector::operator- : Returns the difference between two vectors
//---------------------------------------
template< int D, typename T>

Vector<D, T>	Vector<D, T>::operator-(const Vector<D, T>	&other)
{
	Vector<D, T> theResult;

	for( int i=0; i< D; i++ )
	{
		theResult.coords[i] = this->coords[i] - other.coords[i];
	}

	return theResult;
}





//=================================================================
//	Vector::operator[] : Returns an element of the vector
//---------------------------------------
template< int D, typename T>

T& Vector<D, T>::operator[](size_t index)
{
	return coords[index];
}

#endif