#include <stdio.h>
#include "printb.hpp"

namespace a {
void common_func_a(void)
{
	//std::cout << "This is lib AAAA " << std::endl;
	printf("This is lib AAAA \n");
	b::common_func_b();
}
}

