/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#include <UnitTest++.h>
#include "Vector.h"

SUITE( Vector )
{
	TEST( TEST_vector_1_to_4_default_initializes_to_0 )
	{
		// One-dimensional vector
		Vector<1, float> vect1;

		CHECK_EQUAL( 0, vect1.x );


		// Two-dimensional vector
		Vector<2, float> vect2;

		CHECK_EQUAL( 0, vect2.x );
		CHECK_EQUAL( 0, vect2.y );


		// Three-dimensional vector
		Vector<3, float> vect3;

		CHECK_EQUAL( 0, vect3.x );
		CHECK_EQUAL( 0, vect3.y );
		CHECK_EQUAL( 0, vect3.z );


		// Four-dimensional vector
		Vector<4, float> vect4;

		CHECK_EQUAL( 0, vect4.x );
		CHECK_EQUAL( 0, vect4.y );
		CHECK_EQUAL( 0, vect4.z );
		CHECK_EQUAL( 0, vect4.w );
	}


	TEST( TEST_vector_1_to_4_initialization_general_case )
	{
		// One-dimensional vector
		Vector<1, float> vect1(6);

		CHECK_EQUAL( 6, vect1.x );


		// Two-dimensional vector
		Vector<2, float> vect2(8, 2);

		CHECK_EQUAL( 8, vect2.x );
		CHECK_EQUAL( 2, vect2.y );


		// Three-dimensional vector
		Vector<3, float> vect3(3, 5, 6);

		CHECK_EQUAL( 3, vect3.x );
		CHECK_EQUAL( 5, vect3.y );
		CHECK_EQUAL( 6, vect3.z );


		// Four-dimensional vector
		Vector<4, float> vect4(4, 1, 9, 3);

		CHECK_EQUAL( 4, vect4.x );
		CHECK_EQUAL( 1, vect4.y );
		CHECK_EQUAL( 9, vect4.z );
		CHECK_EQUAL( 3, vect4.w );
	}


	TEST( TEST_vector_addition_and_subtraction_general_case )
	{
		Vector3f vectA(3, 4.5, -2);
		Vector3f vectB(1, 12, 8);


		Vector3f vectC = vectA + vectB;

		CHECK_EQUAL( 4,		vectC.x );
		CHECK_EQUAL( 16.5,	vectC.y );
		CHECK_EQUAL( 6,		vectC.z );


		Vector3f vectD = vectA - vectB;

		CHECK_EQUAL( 2,		vectD.x );
		CHECK_EQUAL( -7.5,	vectD.y );
		CHECK_EQUAL( -10,	vectD.z );
	}


	TEST( TEST_vector_scalar_mult_and_div_general_case )
	{
		Vector3f vect(4, 8, -16);

		Vector3f result = vect*2;

		CHECK_EQUAL( 8,		result.x );
		CHECK_EQUAL( 16,	result.y );
		CHECK_EQUAL( -32,	result.z );
		 

		result = vect/4;

		CHECK_EQUAL( 1,		result.x );
		CHECK_EQUAL( 2,		result.y );
		CHECK_EQUAL( -4,	result.z );
	}
	

	TEST( TEST_vector_length_general_case )
	{
		Vector2f vect2f(3,4);

		CHECK_EQUAL( 5, vect2f.Length() );


		Vector3f vect3f(-3, 4, 8);

		CHECK_CLOSE( 9.433f, vect3f.Length(),	0.001f );


		Vector4d vect4d(4, -2, -5, 6);

		CHECK_EQUAL( 9, vect4d.Length() );
	}


	TEST( TEST_vector_dot_product_general_case )
	{
		Vector3f vectA;
		Vector3f vectB;

		vectA.x = 1;
		vectA.y = 7;
		vectA.z = 12;

		vectB.x = 3;
		vectB.y = -4;
		vectB.z = 2;

		CHECK_EQUAL( -1, vectA.Dot(vectB) );
	}


	TEST( TEST_vector_dot_product_against_self )
	{
		Vector3f vectA(5, -7, 2);

		CHECK_EQUAL( 78, vectA.Dot( vectA ));
		CHECK_CLOSE( vectA.Length()*vectA.Length(),		vectA.Dot( vectA ),		0.001f );
	}


	TEST( TEST_vector_cross_product_general_case )
	{
		Vector3f vectA(3, 5, 2);
		Vector3f vectB(1, 0, -4);

		Vector3f vectC = vectA.Cross( vectB );

		CHECK_EQUAL( -20,	vectC.x );
		CHECK_EQUAL(  14,	vectC.y );
		CHECK_EQUAL(  -5,	vectC.z );
	}


	TEST( TEST_vector_unit_general_case )
	{
		Vector3f vectA(10, -4, 6);

		Vector3f result = vectA.Unit();

		CHECK_CLOSE( 1.0f,		result.Length(),	0.01f );
		CHECK_CLOSE( 0.811f,	result.x,			0.01f );
		CHECK_CLOSE( -0.324f,	result.y,			0.01f );
		CHECK_CLOSE( 0.487f,	result.z,			0.01f );
	}


	// The rotation...	2D :  r' = cos(Q)*r + sin(Q)* (n x r)
	//					3D :  r' = a*(a.r) + rot2D( r-a*(a.r), a, Q)
}