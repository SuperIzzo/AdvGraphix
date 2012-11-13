/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		13/11/2012
 */

#ifndef __APPCMD_PROMPT_H__
#define __APPCMD_PROMPT_H__





//=================================================================
//	Inlude
//---------------------------------------
#include <iostream>





//=================================================================
//	Forward Declarations
//---------------------------------------
class App;





//=================================================================
//	Class App
//---------------------------------------
class AppCmdPrompt
{
public:
							AppCmdPrompt(App &theApp);
	bool					RunSetup();

private:
	void					DoLoadMesh();
	void					DoSetupCamera();
	void					DoSetupGrid();
	void					DoSetupTransforms();
	void					DoAddVectorTransform();

	size_t					GetID(size_t max);

private:
	App					  & mApp;
	std::istream		  * mInStr;
};





#endif