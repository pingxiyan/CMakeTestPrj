#include "mylib.h"

int call_my_lib(std::string str)
{
	std::cout << "This " << __fun__ << " is called" << std::endl;

	return 1;
}
