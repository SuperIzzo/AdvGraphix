/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTORCOMMON_H__
#define __VECTORCOMMON_H__


#include "VectorData.h"


template< int dimensions, typename Type >

struct VectorCommon	: public VectorData< dimensions, Type >
{
public:
							VectorCommon();
							
	Type					Dot(const VectorCommon<dimensions, Type>	 &other);
	Type					Length();

	Type&					operator[] (size_t index);

public:
	typedef	Type			CoordType;
	static const int		DIMENSIONS = dimensions;
};


#include "VectorCommon.inl"

#endif