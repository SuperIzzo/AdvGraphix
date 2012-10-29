/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTORDATA_H__
#define __VECTORDATA_H__


/*
 * The following class is just an unholy hack to get a compile time check on 
 * vector axis names so that they are appropriate for the given Vector dimension.
 * We specialize vectors up to the 4th dimension
 */



// General vector definition only coordinates are accessible
template< int dimensions, typename Type >
struct VectorData
{
	Type		coords[ dimensions ];
};





template< typename Type >
struct VectorData<1, Type>
{
	union
	{
		Type		x;
		Type		coords[1];
	};
};





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
};





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
};





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
};




#endif