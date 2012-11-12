/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTORDATA_H__
#define __VECTORDATA_H__


/*
 * The following class is just an unholy hack to get a compile time check on 
 * vector axis names so that they are appropriate for the given Vector dimension.
 * We specialize vectors up to the 4th dimension... 
 * If you wish more simply include this header and specialize he template
 */



//=================================================================
//	Class VectorData<D, T> : General vector data definition
//---------------------------------------
template< int dimensions, typename Type >
struct VectorData
{
	Type		coords[ dimensions ];

	VectorData() 
	{
		for( int i=0; i< D; i++ )
		{
			coords[i] = 0;
		};
	};
};





//=================================================================
//	Class VectorData<1, T> : One-dimensional vector data
//---------------------------------------
template< typename Type >
struct VectorData<1, Type>
{
	union
	{
		Type		x;
		Type		coords[1];
	};

	VectorData() : x( 0 ) {};
	VectorData( Type aX ) : x( aX ) {};
};





//=================================================================
//	Class VectorData<2, T> : Two-dimensional vector data
//---------------------------------------
template< typename Type >
struct VectorData<2, Type>
{
	union
	{
		struct
		{
			Type		x;
			Type		y;
		};
		Type		coords[2];
	};

	VectorData() : x( 0 ), y( 0 ) {};
	VectorData( Type aX, Type aY ) : x( aX ), y( aY ) {};
};





//=================================================================
//	Class VectorData<3, T> : Three-dimensional vector data
//---------------------------------------
template< typename Type >
struct VectorData<3, Type>
{
	union
	{
		struct
		{
			Type		x;
			Type		y;
			Type		z;
		};
		Type		coords[3];
	};

	VectorData() : x( 0 ), y( 0 ), z( 0 ) {};
	VectorData( Type aX, Type aY, Type aZ ) : x( aX ), y( aY ), z( aZ ) {};
};





//=================================================================
//	Class VectorData<4, T> : Four-dimensional vector data
//---------------------------------------
template< typename Type >
struct VectorData<4, Type>
{
	union
	{
		struct
		{
			Type		x;
			Type		y;
			Type		z;
			Type		w;
		};
		Type		coords[4];
	};

	VectorData() : x( 0 ), y( 0 ), z( 0 ), w( 0 ) {};
	VectorData( Type aX, Type aY, Type aZ, Type aW ) : x( aX ), y( aY ), z( aZ ), w( aW ) {};
};





#endif