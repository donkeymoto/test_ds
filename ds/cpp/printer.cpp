#include "printer.hpp"
#include <iostream>

class PrinterA : public Printer {
	public:
		void printDog(void) {
			std::cout << "AAAAAAAAAA " << " Dog " << "AAAA" << std::endl;
		}

		void printCat(void) {
			std::cout << "AAAAAAAAAAAA" << " cat" << " AAAAAAAAAAA" << std::endl;
		}
};

class PrinterB : public Printer {
	public:
		void printDog(void) {
			std::cout << "BBBBBBBBB " << " Dog " << "BBBBBB " << std::endl;
		}

		void printCat(void) {
			std::cout << "BBBBBBB " << " cat" << " BBBBBBB " << std::endl;
		}
};

class PrinterFactory {
	public:
		static Printer *create(int type) {
			switch (type) {
				case 0:
					return new PrinterA;
				case 1:
					return new PrinterB;
				default:
					return nullptr;
			}
		}
};

Printer *createPrinter(int type) {
	return PrinterFactory::create(type);
}

