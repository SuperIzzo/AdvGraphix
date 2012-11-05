/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		05/11/2012
 */

#ifndef __APP_H__
#define __APP_H__


#include <SFML/Graphics/RenderWindow.hpp>


class App
{
public:
	void					Run();

private:
	void					Initialize();
	void					HandleEvents();
	void					Render();

private:
	sf::RenderWindow		mRenderWindow;
};


#endif