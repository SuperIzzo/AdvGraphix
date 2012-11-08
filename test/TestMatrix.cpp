/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		06/11/2012
 */

#include <UnitTest++.h>
#include "Matrix.h"

SUITE( Matrix )
{
	TEST( TEST_matrix3_adition_general_case )
	{
		Matrix3f mat1;
		Matrix3f mat2;

		mat1(0, 0)	= 3;
		mat1(0, 1)	= 6;
		mat1(0, 2)	= 7;
		mat1(1, 0)	= 5;
		mat1(1, 1)	= 3;
		mat1(1, 2)	= 3;
		mat1(2, 0)	= 1;
		mat1(2, 1)	= 2;
		mat1(2, 2)	= 1;

		mat2(0, 0)	= 7;
		mat2(0, 1)	= 1;
		mat2(0, 2)	= 3;
		mat2(1, 0)	= 3;
		mat2(1, 1)	= 8;
		mat2(1, 2)	= 2;
		mat2(2, 0)	= 2;		
		mat2(2, 1)	= 4;
		mat2(2, 2)	= 9;

		Matrix3f mat3 = mat1 + mat2;

		CHECK_EQUAL( 10,	mat3(0,0) );
		CHECK_EQUAL( 7,		mat3(0,1) );
		CHECK_EQUAL( 10,	mat3(0,2) );
		CHECK_EQUAL( 8,		mat3(1,0) );
		CHECK_EQUAL( 11,	mat3(1,1) );
		CHECK_EQUAL( 5,		mat3(1,2) );
		CHECK_EQUAL( 3,		mat3(2,0) );		
		CHECK_EQUAL( 6,		mat3(2,1) );
		CHECK_EQUAL( 10,	mat3(2,2) );
	}


	TEST( TEST_matrix3_multiplication_general_case )
	{
		Matrix3f mat1;
		Matrix3f mat2;

		mat1(0, 0)	= 2;
		mat1(0, 1)	= 5;
		mat1(0, 2)	= 3;
		mat1(1, 0)	= 4;
		mat1(1, 1)	= 2;
		mat1(1, 2)	= 5;
		mat1(2, 0)	= 1;
		mat1(2, 1)	= 1;
		mat1(2, 2)	= 2;

		mat2(0, 0)	= 7;
		mat2(0, 1)	= 1;
		mat2(0, 2)	= 1;
		mat2(1, 0)	= 3;
		mat2(1, 1)	= 7;
		mat2(1, 2)	= 5;
		mat2(2, 0)	= 6;
		mat2(2, 1)	= 2;
		mat2(2, 2)	= 3;

		Matrix3f mat3 = mat1 * mat2;

		CHECK_EQUAL( 19,	mat3(0,0) );
		CHECK_EQUAL( 38,	mat3(0,1) );
		CHECK_EQUAL( 28,	mat3(0,2) );
		CHECK_EQUAL( 39,	mat3(1,0) );
		CHECK_EQUAL( 34,	mat3(1,1) );
		CHECK_EQUAL( 54,	mat3(1,2) );
		CHECK_EQUAL( 23,	mat3(2,0) );
		CHECK_EQUAL( 37,	mat3(2,1) );
		CHECK_EQUAL( 34,	mat3(2,2) );
	}


	TEST( TEST_matrix3_vector3_multiplication_general_case )
	{
		Matrix3f mat;
		Vector3f vec(3, 4, 6);

		mat(0, 0)	= 3;
		mat(0, 1)	= 5;
		mat(0, 2)	= 3;
		mat(1, 0)	= 5;
		mat(1, 1)	= 2;
		mat(1, 2)	= 1;
		mat(2, 0)	= 6;
		mat(2, 1)	= 2;
		mat(2, 2)	= 5;

		Vector3f result = mat * vec;

		CHECK_EQUAL( 47,	result.x );
		CHECK_EQUAL( 29,	result.y );
		CHECK_EQUAL( 56,	result.z );
	}

	// http://www.purplemath.com/modules/mtrxinvr.htm
}