#include "App.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "Grid3D.h"
#include "TransformUtils.h"





//=================================================================
//	App::Run : Starts the application loop
//---------------------------------------
void App::Run()
{
	Initialize();

	while( mRenderWindow.isOpen() )
	{
		HandleEvents();
		Render();
	}
}





//=================================================================
//	App::Initialize : Initialization phase here
//---------------------------------------
void App::Initialize()
{
	mRenderWindow.create( sf::VideoMode(800, 600), "Graphix Window");

	// Link our 3D renderer to the 2D window
	mGraphics3D.SetRenderTarget( mRenderWindow );

	//Link our camera to the view matrix
	mCamera.SetViewMatrix( &mGraphics3D.GetViewTransform() );
}





//=================================================================
//	App::HandleEvents : Input, windowing events, etc...
//---------------------------------------
void App::HandleEvents()
{
	sf::Event theEvent;
	while( mRenderWindow.pollEvent( theEvent ) )
	{
		if( theEvent.type == sf::Event::Closed )
		{
			mRenderWindow.close();
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

	static float f = 0.00f;
	f+=0.01f;

	mCamera.SetPosition( Vector3f(200+f*5,200,200) );
	mCamera.SetTarget( Vector3f(0, 0+f*5,0) );
	mCamera.SetUpVector( Vector3f(0,0,1) );
	mCamera.Update();


	// Final window adjustments
	TransformUtils::AddTranslation( mGraphics3D.GetViewTransform(), 
		mRenderWindow.getSize().x/2.f, 
		mRenderWindow.getSize().y/2.f, 
		0.0f );


	Grid3D grid;
	grid.Draw( mGraphics3D );


	mRenderWindow.display();
}