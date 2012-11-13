//=================================================================
//	Inlude
//---------------------------------------
#include "AppCmdPrompt.h"
#include "App.h"

#include <iostream>




//=================================================================
//	AppCmdPrompt::AppCmdPrompt
//---------------------------------------
AppCmdPrompt::AppCmdPrompt(App &theApp) :
	mApp( theApp )
{
}





//=================================================================
//	AppCmdPrompt::RunSetup
//---------------------------------------
void AppCmdPrompt::RunSetup()
{
	while( true )
	{
		std::istream *instr = &std::cin;

		std::cout << "Select Action:"
			<< "\n 1) Load mesh"
			<< "\n 2) Setup Camera"
			<< "\n 3) Setup Grid"
			<< "\n 4) Setup Transformation"
			<< "\n 5) Load macro script"
			<< "\n 6) Start!"
			<< "\n 0) QUIT"
			<< std::endl
			<< "> ";

		int option;
		*instr >> option;

		switch( option )
		{
			case 0:
				exit(0);	// Coud be done a little bit les hacky
				break;

			case 1:
				{
					int loadOption = 0;
					std::cout << "Select mesh loader:" 
						<< "\n 1) Vertex and Facet List files"	
						<< "\n 2) OBJ Files"
						<< "\n 0) BACK"
						<< std::endl
						<< "> ";
					
					if( load
				}
				break;
	}
}