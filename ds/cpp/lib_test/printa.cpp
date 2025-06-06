#include <stdio.h>

extern void common_func_b(void);
void common_func_a(void)
{
	//std::cout << "This is lib AAAA " << std::endl;
	printf("This is lib AAAA \n");
	common_func_b();
}

