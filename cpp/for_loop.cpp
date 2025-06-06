#include <iostream>
#include <vector>

int main()
{

	int num = 16;
	int j = 0;
	std::vector<int> data(16);

	for(auto i : data) {
		i = j*10;
		j++;
	}

	for (auto &it : data) {
		std::cout << it << std::endl;
	}

	for(auto &i : data) {
		i = j*10;
		j++;
	}

	for (auto &it : data) {
		std::cout << it << std::endl;
	}

}
