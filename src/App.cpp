#include "App.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include "Grid3D.h"





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

	Grid3D grid;

	mRenderWindow.draw( grid );

	mRenderWindow.display();
}