//=================================================================
//	Inlude
//---------------------------------------
#include "AppCmdPrompt.h"
#include "App.h"

#include "VLFLMeshLoader.h"
#include "OBJMeshLoader.h"



//=================================================================
//	AppCmdPrompt::AppCmdPrompt
//---------------------------------------
AppCmdPrompt::AppCmdPrompt(App &theApp) 
  : mApp( theApp ), 
	mInStr( &std::cin )
{
}





//=================================================================
//	AppCmdPrompt::RunSetup
//---------------------------------------
void AppCmdPrompt::RunSetup()
{
	while( mInStr->good() )
	{
		std::cout << "Select Action:"
			<< "\n 1) Load mesh"
			<< "\n 2) Setup Camera"
			<< "\n 3) Setup Grid"
			<< "\n 4) Setup Transformations"
			<< "\n 5) Load macro script"
			<< "\n 6) Start!"
			<< "\n 0) QUIT"
			<< std::endl
			<< "> ";

		int option;
		*mInStr >> option;

		switch( option )
		{
			case 0:
				exit(0);	// Coud be done a little bit less hacky
				break;

			case 1:
				DoLoadMesh();
				break;

			case 2:
				DoSetupCamera();
				break;

			case 6:
				return;
				break;
		}
	}
}





//=================================================================
//	AppCmdPrompt::DoLoadMesh
//---------------------------------------
void AppCmdPrompt::DoLoadMesh()
{
	int loadOption = 0;
	std::cout << "Select mesh loader:" 
		<< "\n 1) Vertex and Facet List files"	
		<< "\n 2) OBJ file"
		<< "\n 0) BACK"
		<< std::endl
		<< "> ";

	*mInStr >> loadOption;
					
	if( loadOption == 1 )
	{					
		char vlFile[255];
		char flFile[255];

		std::cout << "Enter the vertex list file path:" 
			<< std::endl
			<< "> ";							
		*mInStr >> vlFile;

		std::cout << "Enter the facet list file path:" 
			<< std::endl
			<< "> ";							
		*mInStr >> flFile;

		if( ! VLFLMeshLoader::LoadMesh( mApp.mMesh, vlFile, flFile ) )
		{
			std::cout << "Error loading mesh from files." << std::endl;
		}
	}
	else if( loadOption == 2 )
	{
		char objFile[255];

		std::cout << "Enter the OBJ file path:" 
			<< std::endl
			<< "> ";
		*mInStr >> objFile;

		if( ! OBJMeshLoader::LoadMesh( mApp.mMesh, objFile ) )
		{
			std::cout << "Error loading mesh from file." << std::endl;
		}
		else
		{
			std::cout << "Mesh loaded successfully!" << std::endl;
		}
	}
}





//=================================================================
//	AppCmdPrompt::DoSetupCamera
//---------------------------------------
void AppCmdPrompt::DoSetupCamera() 
{
	while( true )
	{
		int cameraOption = 0;
		std::cout << "Select action:" 
			<< "\n 1) Set camera position"	
			<< "\n 2) Set camera target"
			<< "\n 3) Set camera up vector"
			<< "\n 0) BACK"
			<< std::endl
			<< "> ";

		*mInStr >> cameraOption;

		switch( cameraOption )
		{
			case 1:
				{
					Vector3f thePos;
					std::cout << "Enter position coordinates (in x,y,z order):";

					*mInStr >> thePos.x;
					*mInStr >> thePos.y;
					*mInStr >> thePos.z;

					mApp.mCamera.Position() = thePos;
				}
				break;

			case 2:
				{
					Vector3f theTarget;
					std::cout << "Enter target coordinates (in x,y,z order):";

					*mInStr >> theTarget.x;
					*mInStr >> theTarget.y;
					*mInStr >> theTarget.z;

					mApp.mCamera.Target() = theTarget;
				}
				break;

			case 3:
				{
					Vector3f theUpVec;
					std::cout << "Enter target coordinates (in x,y,z order):";

					*mInStr >> theUpVec.x;
					*mInStr >> theUpVec.y;
					*mInStr >> theUpVec.z;

					mApp.mCamera.UpVector() = theUpVec.Unit();
				}
				break;

			case 0:
				return; //Go back!
				break;
		}
	}
}