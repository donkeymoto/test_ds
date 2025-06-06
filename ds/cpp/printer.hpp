class Printer {
	public:
		virtual void printDog(void) = 0;
		virtual void printCat(void) = 0;
};

Printer *createPrinter(int type);

