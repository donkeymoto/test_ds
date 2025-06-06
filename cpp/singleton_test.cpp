#include <iostream>

class Singleton {
	public:
		Singleton();
		~Singleton();
		static Singleton& getInstance(void);
		int getFlag(void) { return flag; }
		int setFlag(int f) { flag = f; }
	private:
		int flag;
};

Singleton::Singleton()
{
	std::cout << "Singleton class is constructed +++" << std::endl;
}

Singleton::~Singleton()
{
	std::cout << "Singleton class is destructed ---" << std::endl;
}

Singleton& Singleton::getInstance(void)
{
	static Singleton sc;
	return sc;
}

int main(void)
{
	{
		auto &aa = Singleton::getInstance();
		aa.setFlag(1010);
		std::cout << "flag is : " << aa.getFlag() << std::endl;
	}

	std::cout << "out of range" << std::endl;

	int a = 5;
	int& ra = a;
	std::cout << "obj a: " << &a << std::endl << "obj ra: " << &ra << std::endl;

}
