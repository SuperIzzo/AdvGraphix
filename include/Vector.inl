/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#ifndef __VECTOR_INL__
#define __VECTOR_INL__





//=================================================================
// Vector<1>::Vector()
//---------------------------------------
template< typename Type >
Vector<1, Type>::Vector()
{
}





//=================================================================
// Vector<1>::Vector(x)
//---------------------------------------
template< typename Type >
Vector<1, Type>::Vector(Type aX)
{
	x = aX;
}





//=================================================================
// Vector<2>::Vector()
//---------------------------------------
template< typename Type >
Vector<2, Type>::Vector()
{
}





//=================================================================
// Vector<2>::Vector(x,y)
//---------------------------------------
template< typename Type >
Vector<2, Type>::Vector(Type aX, Type aY)
{
	x = aX;
	y = aY;
}





//=================================================================
// Vector<3>::Vector()
//---------------------------------------
template< typename Type >
Vector<3, Type>::Vector()
{
}





//=================================================================
// Vector<3>::Vector(x,y,z)
//---------------------------------------
template< typename Type >
Vector<3, Type>::Vector(Type aX, Type aY, Type aZ)
{
	x = aX;
	y = aY;
	z = aZ;
}





//=================================================================
// Vector<4>::Vector()
//---------------------------------------
template< typename Type >
Vector<4, Type>::Vector()
{
}





//=================================================================
// Vector<4>::Vector(x,y,z,w)
//---------------------------------------
template< typename Type >
Vector<4, Type>::Vector(Type aX, Type aY, Type aZ, Type aW)
{
	x = aX;
	y = aY;
	z = aZ;
	w = aW;
}

#endif