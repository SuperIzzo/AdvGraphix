/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		05/11/2012
 */

#ifndef __APP_H__
#define __APP_H__





//=================================================================
//	Inlude
//---------------------------------------
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Graphics3D.h"
#include "Camera.h"

#include "Mesh.h"
#include "TransformOperation.h"
#include "AppCmdPrompt.h"





//=================================================================
//	Class App
//---------------------------------------
class App
{
public:
							App();
	void					Run();

	void					SetMesh( const Mesh &theMesh );
	void					SetTransformOp( TransformOperation *transformOp );

private:
	void					Initialize();
	void					SetUpScene();
	void					UserPrompt();
	void					HandleEvents();
	void					HandleKeyPressedEvent( sf::Event &theEvent );
	void					HandleKeyReleasedEvent( sf::Event &theEvent );
	void					Update();
	void					Render();

private:
	Camera					mCamera;
	Graphics3D				mGraphics3D;
	sf::RenderWindow		mRenderWindow;
	bool					mKeyBuffer[sf::Keyboard::KeyCount];

	TransformOperation	  * mTransformOperation;
	Mesh					mMesh;
	Mesh					mTransformedMesh;

	AppCmdPrompt			mCmdPrompt;

	friend class AppCmdPrompt;
};





#endif
