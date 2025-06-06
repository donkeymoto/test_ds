#include <iostream>
#include <fstream>
#include <vector>

int main(void)
{
	void *p = malloc(10);
	free(0);
	free(p);
	std::cout << "p is : " << p << std::endl;
}
