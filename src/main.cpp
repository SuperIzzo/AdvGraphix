/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */





//=================================================================
//	Inlude
//---------------------------------------
#include <Windows.h>
#include <UnitTest++.h>
#include <cstdio>

#include "App.h"

#include "ShiftTransform.h"
#include "ScaleTransform.h"



//=================================================================
//	main
//---------------------------------------
int main(int argc, char* args[])
{
	if ( argc > 1   &&   strcmp("-test", args[1])==0 )
	{
		int result = 0;

		printf("\n--=-=-=-==== Test ====-=-=-=--\n");
		result = UnitTest::RunAllTests();
		printf( "--=-=-=-== = == == == = ==-=-=-=--\n\n");

		return result;
	}
	else
	{		
		/*
		Mesh theMesh;
		bool meshLoaded;

		theMesh.SetColor( sf::Color::Magenta );

		meshLoaded = OBJMeshLoader::LoadMesh( theMesh, 
			"..\\..\\..\\data\\books.obj"
		);
		
		ShiftTransform theShift( Vector3f(100, 100, 100) );

		Vector3f scaleDir = Vector3f(1, 1, 1).Unit();

		ScaleTransform theScale( scaleDir, 3 );
		*/

		App theApp;

		//theApp.SetMesh( theMesh );
		//theApp.SetTransformOp( &theScale );
		theApp.Run();
	}
}