//=================================================================
//	Inlude
//---------------------------------------
#include "App.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "Grid3D.h"
#include "TransformUtils.h"



//=================================================================
//	App::App
//---------------------------------------
App::App() :
	mTransformOperation( 0 ),
	mCmdPrompt( *this )
{
	memset( mKeyBuffer, 0, sizeof(mKeyBuffer) );
}





//=================================================================
//	App::SetMesh : Set the mesh
//---------------------------------------
void App::SetMesh(const Mesh &theMesh)
{
	mMesh = theMesh;
}





//=================================================================
//	App::SetTransformOp : Set the transform operation
//---------------------------------------
void App::SetTransformOp( TransformOperation *transformOp )
{
	mTransformOperation = transformOp;
}




//=================================================================
//	App::Run : Starts the application loop
//---------------------------------------
void App::Run()
{
	Initialize();

	while( mRenderWindow.isOpen() )
	{
		HandleEvents();
		Update();
		Render();
	}
}





//=================================================================
//	App::Initialize : Initialization phase here
//---------------------------------------
void App::Initialize()
{
	UserPrompt();

	// Create our window
	mRenderWindow.create( sf::VideoMode(800, 600), "Graphix Window");

	// Link our 3D renderer to the 2D window
	mGraphics3D.SetRenderTarget( mRenderWindow );

	// Link our camera to the view matrix
	mCamera.SetViewMatrix( &mGraphics3D.ViewTransform() );

	// Setup our meshes
	SetUpScene();


	// Setup camera position
	mCamera.Position() = Vector3f(200,200,200);
	mCamera.UpVector() = Vector3f(0,1,0);
}





//=================================================================
//	App::UserPrompt : Prompt the user for options
//---------------------------------------
void App::UserPrompt()
{
	mCmdPrompt.RunSetup();
}





//=================================================================
//	App::SetUpScene : Setup our meshes
//---------------------------------------
void App::SetUpScene()
{
	mMesh.SetColor( sf::Color::Magenta );
	mTransformedMesh.SetColor( sf::Color::Yellow );

	if( mTransformOperation )
	{
		mTransformedMesh.mFacets = mMesh.mFacets;

		mTransformedMesh.mVertices.clear();
		mTransformedMesh.mVertices.reserve( mMesh.mVertices.size() );

		std::vector<Vector3f>::iterator vert = mMesh.mVertices.begin();
		for( ; vert != mMesh.mVertices.end(); ++vert )
		{
			mTransformedMesh.mVertices.push_back(
				mTransformOperation->Transform( *vert )
			);
		}
	}
}





//=================================================================
//	App::HandleEvents : Input, windowing events, etc...
//---------------------------------------
void App::HandleEvents()
{
	sf::Event theEvent;
	while( mRenderWindow.pollEvent( theEvent ) )
	{
		switch( theEvent.type )
		{
			case sf::Event::Closed :
				mRenderWindow.close();
				break;

			case sf::Event::KeyPressed  :
				HandleKeyPressedEvent( theEvent );
				break;

			case sf::Event::KeyReleased :
				HandleKeyReleasedEvent( theEvent );
				break;
		}
	}
}





//=================================================================
//	App::HandleKeyPressedEvent : Key pressed events handled here
//---------------------------------------
void App::HandleKeyPressedEvent( sf::Event &theEvent )
{
	mKeyBuffer[ theEvent.key.code ] = true;
}





//=================================================================
//	App::HandleKeyReleasedEvent : Key released events handled here
//---------------------------------------
void App::HandleKeyReleasedEvent( sf::Event &theEvent )
{
	mKeyBuffer[ theEvent.key.code ] = false;
}





//=================================================================
//	App::Update : Updates any logic 
//---------------------------------------
void App::Update()
{
	bool upKey		= mKeyBuffer[ sf::Keyboard::Up ];
	bool downKey	= mKeyBuffer[ sf::Keyboard::Down ];
	bool leftKey	= mKeyBuffer[ sf::Keyboard::Left ];
	bool rightKey	= mKeyBuffer[ sf::Keyboard::Right ];

	if( upKey || downKey || leftKey || rightKey )
	{
		float camSpeed = 3.0f;

		Vector3f &camPos = mCamera.Position();
		Vector3f camDir = (mCamera.Target() - camPos).Unit();
		Vector3f camUp =  mCamera.UpVector();

		Vector3f camRight =  camUp.Cross( camDir );

		if( upKey )
		{
			camPos = camPos + camUp * camSpeed;
		}
		else if( downKey )
		{
			camPos = camPos - camUp * camSpeed;
		}

		if( rightKey )
		{
			camPos = camPos + camRight * camSpeed;
		}
		else if( leftKey )
		{
			camPos = camPos - camRight * camSpeed;
		}
	}
}





//=================================================================
//	App::Render : Does the drawing
//---------------------------------------
void App::Render()
{
	mCamera.Update();
	mRenderWindow.clear();

	// Drawing code here

	mCamera.Update();


	// Final window adjustments
	TransformUtils::AddTranslation( mGraphics3D.ViewTransform(), 
		mRenderWindow.getSize().x/2.f, 
		mRenderWindow.getSize().y/2.f, 
		0.0f );


	Grid3D grid;
	grid.Draw( mGraphics3D );

	mMesh.Draw( mGraphics3D );
	mTransformedMesh.Draw( mGraphics3D );

	mRenderWindow.display();
}