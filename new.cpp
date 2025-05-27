#include <iostream>

int main()
{
	int *x;
	x = new int(22);
	std::cout << "x = " << *x << std::endl;
	*x = 11;
	std::cout << "x = " << *x << std::endl;
	delete x;
}
