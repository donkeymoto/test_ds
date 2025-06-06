// main.cpp
#include <memory>
#include <thread>
#include <vector>
#include <iostream>
#include <pthread.h>

#if 0
thread_local std::vector<int> vecNumbers;
void f() {
	for (int i = 0; i < 10; i++) {
		vecNumbers.push_back(i);
	}

	std::cout << "Size of vector: " << vecNumbers.size() << std::endl;
}


int main() {

	std::thread th(f);

	std::cout << "Size of vector: " << vecNumbers.size() << std::endl;

	th.join();

	std::cout << "Size of vector: " << vecNumbers.size() << std::endl;

	for (auto i : vecNumbers) {
		std::cout << "m" << i << " ";
	}

	std::cout << std::endl;

	return 0;
}
#endif

//main.cpp
#include <memory>
#include <thread>

void f() {
	thread_local std::shared_ptr<int> ptr = std::make_shared<int>(0);
}

int main() {
	std::thread th(f);
	th.join();
	return 0;
}
