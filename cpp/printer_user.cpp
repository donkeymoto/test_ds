#include "printer.hpp"
#include <iostream>

int main() {
	std::cout << "create printer A: " << std::endl;
	auto p = createPrinter(0);
	p->printDog();
	p->printCat();
	delete p;

	std::cout << "create printer B: " << std::endl;
	p = createPrinter(1);
	p->printDog();
	p->printCat();
	delete p;

}
