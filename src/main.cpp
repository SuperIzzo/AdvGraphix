/*
 * Author:		Hristoz Stefanov Stefanov
 * Created:		29/10/2012
 */

#include <Windows.h>
#include <UnitTest++.h>
#include <cstdio>


int main(int argc, char* args[])
{
	int result = 0;

	printf("\n--=-=-=-==== Test ====-=-=-=--\n");
    result = UnitTest::RunAllTests();
	printf( "--=-=-=-== = == == == = ==-=-=-=--\n\n");

	return result;
}