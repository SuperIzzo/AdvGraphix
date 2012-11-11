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
	mRenderWindow.clear();
	
	// Drawing code here

	TransformUtils::AddRotationZ(	mGraphics3D.GetViewTransform(), 0.01f );


	Matrix4f persp;
	TransformUtils::SetIdentity( persp );

	//persp(1,3) = -1;
	//persp(2,3) = -1;


	Matrix4f & the3DView = mGraphics3D.GetViewTransform();

	static float f = 0.00f;
	f+=0.01;

	TransformUtils::SetIdentity(	the3DView );


	// Perspective hack
	persp(3,3) = 0.5;
	persp(3,2) = 1/600;
	
	printf("%f\n", f);

	TransformUtils::AddRotationZ(	the3DView, 45.0f + f);
	TransformUtils::AddRotationX(	the3DView, 60.f );

	the3DView = the3DView * persp;

	TransformUtils::AddTranslation( the3DView, 300.f, 300.f, 0.0f );

	TransformUtils::SetLookAt( the3DView, Vector3f(200+f*5,200,200), Vector3f(0, 0+f*5,0), Vector3f(0,0,1) );

	the3DView = the3DView * persp;

	// Final window adjustments
	TransformUtils::AddTranslation( the3DView, mRenderWindow.getSize().x/2.f, mRenderWindow.getSize().y/2.f, 0.0f );


	Grid3D grid;
	grid.Draw( mGraphics3D );


	mRenderWindow.display();
}