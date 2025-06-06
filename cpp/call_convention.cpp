#include <iostream>

void testArgsPass(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	std::cout << "a:" << a
						<< " b:" << b
						<< " c:" << c
						<< " d:" << d
						<< " e:" << e
						<< " f:" << f
						<< " g:" << g
						<< " h:" << h
						<< " i:" << i
						<< std::endl;
}
int main(void)
{

	testArgsPass(1, 2, 3, 4, 5, 6, 7, 8, 9);
	return 0;
}

