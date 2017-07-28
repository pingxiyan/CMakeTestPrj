#include "header.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

#ifndef _WIN32
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#endif

int main(int argc, char** argv)
{
	test("this first test cmake");
	
	double inputValue = 2;
#ifdef USE_MYMATH
	inputValue = 2;
	double outputValue = mysqrt(inputValue);
	printf("USE_MYMAT: The square root of %g is %g\n", inputValue, outputValue);
#else
	inputValue = 3;
	double outputValue = sqrt(inputValue);
	printf("USE_LIBMATH: The square root of %g is %g\n", inputValue, outputValue);
#endif

	return 0;
}
	
