/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#include <UnitTest++.h>
#include "Vector.h"

SUITE( Vector )
{
	TEST( TEST_Vector1to4InitializesWith0 )
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


	TEST( TEST_Vector1to4ConstructorInitializesProperly )
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

	
	TEST( TEST_VectorLengthWorks )
	{
		Vector2f vect2f(3,4);

		CHECK_EQUAL( 5, vect2f.Length() );


		Vector3f vect3f(-3, 4, 8);

		CHECK_CLOSE( 9.433f, vect3f.Length(),	0.001f );


		Vector4d vect4d(4, -2, -5, 6);

		CHECK_EQUAL( 9, vect4d.Length() );
	}


	TEST( TEST_VectorDotProductWorks )
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


	TEST( TEST_VectorDotAgainstSelfWorks )
	{
		Vector3f vectA(5, -7, 2);

		CHECK_EQUAL( 78, vectA.Dot( vectA ));
		CHECK_CLOSE( vectA.Length()*vectA.Length(),		vectA.Dot( vectA ),		0.001f );
	}
}