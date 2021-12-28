#include "mylib.h"

int call_my_lib(std::string str)
{
	std::cout << "This " << __FUNCTION__ << " is called" << std::endl;
	std::cout << "Param: " << str << std::endl;

	return 1;
}
