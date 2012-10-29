/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTORCOMMON_INL__
#define __VECTORCOMMON_INL__





//=================================================================
//	VectorCommon::Dot : Returns the dot product between two vectors
//---------------------------------------
template< int D, typename T>

VectorCommon<D, T>::VectorCommon()
{
	for( int i=0; i< D; i++ )
	{
		coords[i] = 0;
	}
}





//=================================================================
//	VectorCommon::Dot : Returns the dot product between two vectors
//---------------------------------------
template< int D, typename T>

T VectorCommon<D, T>::Dot(const VectorCommon<D, T> &other)
{
	T result = 0;

	for( int i=0; i<D; i++ )
	{
		result += this->coords[i] * other.coords[i];
	}

	return result;
}





//=================================================================
//	VectorCommon::Length : Returns the length of a vector
//---------------------------------------
template< int D, typename T>

T VectorCommon<D, T>::Length()
{
	T result = 0;

	for( int i=0; i<D; i++ )
	{
		result += coords[i] * coords[i];
	}

	return (T) sqrt(result);
}





//=================================================================
//	VectorCommon::Dot : Returns the dot product between two vectors
//---------------------------------------
template< int D, typename T>

T& VectorCommon<D, T>::operator[](size_t index)
{
	return coords[index];
}

#endif