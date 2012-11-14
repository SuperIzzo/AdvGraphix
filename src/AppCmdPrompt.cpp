//=================================================================
//	Inlude
//---------------------------------------
#include "AppCmdPrompt.h"
#include "App.h"

#include <fstream>
#include <sstream>
#include <SFML/System/Clock.hpp>
#include "VLFLMeshLoader.h"
#include "OBJMeshLoader.h"

#include "ShiftTransform.h"
#include "ScaleTransform.h"
#include "ReflectTransform.h"

#include "MatrixTransform.h"


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
bool AppCmdPrompt::RunSetup()
{
	while( true )
	{
		// Terminate a macro if it is over
		if( !mInStr->good() )
		{
			if( mInStr != &std::cin )
				mInStr = &std::cin; 
		}

		std::cout << "Select Action:"
			<< "\n 1) Load mesh"
			<< "\n 2) Setup Grid"
			<< "\n 3) Setup Camera"
			<< "\n 4) Setup Transformations"
			<< "\n 5) Load macro script"
			<< "\n 6) Start!"
			<< "\n 0) QUIT"
			<< std::endl
			<< "> ";

		int option;
		*mInStr >> option;
		std::cout << std::endl;

		switch( option )
		{
			case 0:
				return false;
				break;

			case 1:
				DoLoadMesh();
				break;

			case 2:
				DoSetupGrid();
				break;

			case 3:
				DoSetupCamera();
				break;

			case 4:
				DoSetupTransforms();
				break;

			case 5:
				DoLoadMacroScript();
				break;

			case 6:
				std::cout << "\n\nStarting up! To bring the console back any time press ESC" << std::endl;
				return true;
				break;
		}
	}

	std::cout << "Unexpected error, probably a macro script failure" << std::endl;
	return true;
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
	std::cout << std::endl;
					
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
//	AppCmdPrompt::DoSetupGrid : setup the grid
//---------------------------------------
void AppCmdPrompt::DoSetupGrid()
{
	while( true )
	{
		// Print out some info about the grid
		std::cout << "\n\n3D Grid"

			"\n  * position - "
			<< mApp.mGrid.Position().x << ", " 
			<< mApp.mGrid.Position().y << ", " 
			<< mApp.mGrid.Position().z << 

			"\n  * size - " 
			<< mApp.mGrid.Size().x << ", " 
			<< mApp.mGrid.Size().y << ", " 
			<< mApp.mGrid.Size().z <<

			"\n  * spacing - " 
			<< mApp.mGrid.Spacing().x << ", " 
			<< mApp.mGrid.Spacing().y << ", " 
			<< mApp.mGrid.Spacing().z << 
			
			"\n" <<std::endl;

		// Ask the user what they want to do
		int gridOption = 0;
		std::cout << "Select action:" 
			<< "\n 1) Set grid position"	
			<< "\n 2) Set grid size"
			<< "\n 3) Set grid spacing"
			<< "\n 0) BACK"
			<< std::endl
			<< "> ";

		*mInStr >> gridOption;
		std::cout << std::endl;

		switch( gridOption )
		{
			// Set grid position
			case 1:
				{
					Vector3f thePos;
					std::cout << "Enter position coordinates (in x,y,z order): ";

					*mInStr >> thePos.x;
					*mInStr >> thePos.y;
					*mInStr >> thePos.z;

					mApp.mGrid.Position() = thePos;
				}
				break;

			// Set grid size
			case 2:
				{
					Vector3f theSize;
					std::cout << "Enter the size dimensions (in x,y,z order): ";

					*mInStr >> theSize.x;
					*mInStr >> theSize.y;
					*mInStr >> theSize.z;

					mApp.mGrid.Size() = theSize;
				}
				break;

			// Set grid spacing
			case 3:
				{
					Vector3f theSpacing;
					std::cout << "Enter the spacing dimensions (in x,y,z order): ";

					*mInStr >> theSpacing.x;
					*mInStr >> theSpacing.y;
					*mInStr >> theSpacing.z;

					mApp.mGrid.Spacing() = theSpacing;
				}
				break;

			// BACK
			case 0:
				return;
				break;
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
		// Print out some info about the camera
		std::cout << "\n\nCamera"

			"\n  * position - "
			<< mApp.mCamera.Position().x << ", " 
			<< mApp.mCamera.Position().y << ", " 
			<< mApp.mCamera.Position().z << 

			"\n  * target - " 
			<< mApp.mCamera.Target().x << ", " 
			<< mApp.mCamera.Target().y << ", " 
			<< mApp.mCamera.Target().z <<

			"\n  * up - " 
			<< mApp.mCamera.UpVector().x << ", " 
			<< mApp.mCamera.UpVector().y << ", " 
			<< mApp.mCamera.UpVector().z << 

			"\n  * zoom - "
			<< mApp.mCamera.Zoom() <<

			"\n" << std::endl;

		int cameraOption = 0;
		std::cout << "Select action:" 
			<< "\n 1) Set camera position"	
			<< "\n 2) Set camera target"
			<< "\n 3) Set camera up vector"
			<< "\n 4) Set camdera zoom"
			<< "\n 0) BACK"
			<< std::endl
			<< "> ";

		*mInStr >> cameraOption;
		std::cout << std::endl;

		switch( cameraOption )
		{
			// Set camera position
			case 1:
				{
					Vector3f thePos;
					std::cout << "Enter position coordinates (in x,y,z order): ";

					*mInStr >> thePos.x;
					*mInStr >> thePos.y;
					*mInStr >> thePos.z;

					mApp.mCamera.Position() = thePos;
				}
				break;

			// Set camera target
			case 2:
				{
					Vector3f theTarget;
					std::cout << "Enter target coordinates (in x,y,z order): ";

					*mInStr >> theTarget.x;
					*mInStr >> theTarget.y;
					*mInStr >> theTarget.z;

					mApp.mCamera.Target() = theTarget;
				}
				break;

			// Set camera up vector
			case 3:
				{
					Vector3f theUpVec;
					std::cout << "Enter up vector (in x,y,z order): ";

					*mInStr >> theUpVec.x;
					*mInStr >> theUpVec.y;
					*mInStr >> theUpVec.z;

					mApp.mCamera.UpVector() = theUpVec.Unit();
				}
				break;

			// Set camera zoom
			case 4:
				{
					std::cout << "Enter zoom: ";

					*mInStr >> mApp.mCamera.Zoom();
				}
				break;

			// BACK
			case 0:
				return;
				break;
		}
	}
}





//=================================================================
//	AppCmdPrompt::DoSetupTransforms
//---------------------------------------
void AppCmdPrompt::DoSetupTransforms()
{
	while( true )
	{
		//mApp.mTransformOperations.push_back( new ShiftTransform( Vector3f(100,100,100) ) );

		// Print out some info about the camera
		std::cout << "\n\nTransformations - " << mApp.mTransformOperations.size() << std::endl;

		for( size_t i = 0; i < mApp.mTransformOperations.size(); i++ )
		{
			std::cout << "  [" << i << "] ";
			mApp.mTransformOperations[i]->Display( std::cout );
			std::cout << std::endl;
		}


		// Ask the user what they want to do
		int gridOption = 0;
		std::cout << "Select action:" 
			<< "\n 1) Add vector transform"	
			<< "\n 2) Add matrix transform"	 // When adding a matrix next to another matrix the two matrices are merged
			<< "\n 3) Remove transform"
			<< "\n 4) Profile transforms"
			<< "\n 0) BACK"
			<< std::endl
			<< "> ";

		*mInStr >> gridOption;
		std::cout << std::endl;

		switch( gridOption )
		{
			// Add vector
			case 1:
				DoAddTransform(false);
				break;

			// Add vector
			case 2:
				DoAddTransform(true);
				break;

			// Remove transform
			case 3:
				{
					if( !mApp.mTransformOperations.empty() )
					{
						std::cout << "Enter transform ID: ";
						size_t id = GetID( mApp.mTransformOperations.size()-1 );
					
						delete mApp.mTransformOperations[id];
						mApp.mTransformOperations.erase( mApp.mTransformOperations.begin() + id );
					}
				}
				break;

			case 4:
				DoProfileTransforms();
				break;

			// BACK
			case 0:
				return;
				break;
		}
	}
}





//=================================================================
//	AppCmdPrompt::DoAddTransform
//---------------------------------------
void AppCmdPrompt::DoAddTransform(bool mat)
{
	TransformOperation * theOp = NULL;

	std::cout << "Insert before ID: ";
	size_t id = GetID( mApp.mTransformOperations.size() );

	int transfType;
	std::cout << "Select transform type:" 
				<< "\n 1) Shift"	
				<< "\n 2) Scale"
				<< "\n 3) Rotation"
				<< "\n 4) Reflection"
				<< std::endl
				<< "> ";

	*mInStr >> transfType;
	std::cout << std::endl;
	
	switch( transfType )
	{
		// Shift transform
		case 1:
			{
				Vector3f theShift;

				std::cout << "Enter shift vector (in x,y,z order): ";

				*mInStr >> theShift.x;
				*mInStr >> theShift.y;
				*mInStr >> theShift.z;
				
				theOp = new ShiftTransform( theShift );
			}
			break;

		// Scale transform
		case 2:
			{
				Vector3f	theDir;
				float		alpha;

				std::cout << "Enter direction vector (in x,y,z order): ";

				*mInStr >> theDir.x;
				*mInStr >> theDir.y;
				*mInStr >> theDir.z;

				std::cout << "Enter alpha: ";

				*mInStr >> alpha;
				
				theOp = new ScaleTransform( theDir.Unit(), alpha );
			}
			break;

		// Rotate transform
		case 3:
			break;

		// Reflect transform
		case 4:
			{
				Vector3f	theNorm;
				std::cout << "Enter the reflector surface normal (in x,y,z order): ";

				*mInStr >> theNorm.x;
				*mInStr >> theNorm.y;
				*mInStr >> theNorm.z;

				theOp = new ReflectTransform( theNorm.Unit() );
			}
	}

	if( !mat )
	{
		// Add vector operation
		mApp.mTransformOperations.insert( mApp.mTransformOperations.begin() + id, theOp );
	}
	else
	{
		// Add matrix operation
		// This is a bit trickier because we won't necesssaryly be adding a new object
		// Instead we'll check wether there is a matrix before or after and multiply the matrices
		MatrixTransform * matOp = 0;
		bool post = false;

		if( id < mApp.mTransformOperations.size() )
		{
			TransformOperation * currentOp = mApp.mTransformOperations[id];

			if( currentOp->GetType() == MatrixTransform::TRANSFORM_TYPE )
			{
				matOp = (MatrixTransform*) currentOp;
				post = false;
			}
		}
		
		if( matOp == 0 && id>0 )
		{
			TransformOperation * currentOp = mApp.mTransformOperations[id-1];

			if( currentOp->GetType() == MatrixTransform::TRANSFORM_TYPE )
			{
				matOp = (MatrixTransform*) currentOp;
				post = true;
			}
		}

		Matrix4f theMat = theOp->BuildMatrix();
		std::ostringstream theCaption;

		theOp->Display( theCaption );

		if( matOp )
		{
			if( post )
			{
				matOp->matrix = matOp->matrix * theMat;
				matOp->operations.push_back( theCaption.str() );
			}
			else
			{
				matOp->matrix = theMat * matOp->matrix;
				matOp->operations.insert( matOp->operations.begin(), theCaption.str() );
			}
		}
		else
		{
			MatrixTransform *theMatOp = new MatrixTransform( theMat, theCaption.str() );
			mApp.mTransformOperations.insert( mApp.mTransformOperations.begin() + id, theMatOp );
		}

		delete theOp;
	}
}





//=================================================================
//	AppCmdPrompt::GetID : an utility function get a correct number
//---------------------------------------
size_t AppCmdPrompt::GetID(size_t max)
{
	size_t id = 0;
	
	while( true )
	{							
		*mInStr >> id;

		if( id>=0 && id <= max )
		{
			break;
		}
		else
		{
			std::cout << "Wrong ID. Enter a number between 0 and " 
					  << max << std::endl;
		}
	}

	return id;
}





//=================================================================
//	AppCmdPrompt::DoLoadMacroScript
//---------------------------------------
void AppCmdPrompt::DoLoadMacroScript()
{
	char macroFName[255];

	std::cout << "Enter the macro file path:"
		<< std::endl
		<< "> ";							
	*mInStr >> macroFName;

	if( strcmp(macroFName, "IO") == 0 )
	{
		if( mInStr != &std::cin)
		{
			delete mInStr;
			mInStr = &std::cin;
		}
	}
	else
	{
		mInStr = new std::ifstream(macroFName);
	}
}





//=================================================================
//	AppCmdPrompt::DoProfile
//---------------------------------------
void AppCmdPrompt::DoProfileTransforms()
{
	int numPoints;

	std::cout << "Enter number of points to operate on:";
	*mInStr >> numPoints;

	std::vector<TransformOperation*>::iterator beginI = mApp.mTransformOperations.begin();
	std::vector<TransformOperation*>::iterator endI = mApp.mTransformOperations.end();

	sf::Clock proffiler;
	proffiler.restart();
	for( int i = 0; i< numPoints; i++)
	{
		Vector3f dummyPoint(  (rand() % 10000)/100,  (rand() % 10000)/100,	(rand() % 10000)/100 );

		for( std::vector<TransformOperation*>::iterator i=beginI; i!= endI; ++i )
		{
			dummyPoint = (*i)->Transform( dummyPoint );
		}
	}
	sf::Time delta = proffiler.getElapsedTime();

	std::cout << "Operations completed in: " << delta.asMilliseconds() << " milliseconds" << std::endl;
}