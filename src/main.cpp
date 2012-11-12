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

#include "VLFLMeshLoader.h"
#include "OBJMeshLoader.h"





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
		/*Mesh theMesh;
		OBJMeshLoader::LoadMesh( theMesh, 
			"M:\\Advance Computer Graphics\\Assignment 1\\AdvGraphix\\data\\vase.obj"
			);

		system( "pause" );
		return 0;*/
		
		App theApp;

		theApp.Run();
	}
}