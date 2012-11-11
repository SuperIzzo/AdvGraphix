/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		05/11/2012
 */

#ifndef __APP_H__
#define __APP_H__


#include <SFML/Graphics/RenderWindow.hpp>
#include "Graphics3D.h"
#include "Camera.h"


class App
{
public:
	void					Run();

private:
	void					Initialize();
	void					HandleEvents();
	void					Render();

private:
	Camera					mCamera;
	Graphics3D				mGraphics3D;
	sf::RenderWindow		mRenderWindow;
};


#endif