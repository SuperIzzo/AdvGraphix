/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#include <Windows.h>
#include <UnitTest++.h>
#include <cstdio>


#include "App.h"




int main(int argc, char* args[])
{
	if ( argc > 1   &&   strcmp("-test", args[1])==0 )
	{
		int result = 0;

		printf("\n--=-=-=-==== Test ====-=-=-=--\n");
		result = UnitTest::RunAllTests();
		printf( "--=-=-=-== = == == == = ==-=-=-=--\n\n");

		return result;
	}
	else
	{
		App theApp;

		theApp.Run();
	}
}