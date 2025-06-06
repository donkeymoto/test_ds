#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

int main(void)
{
	bitset<64> bitvet(0xff00ff0ffff);

	cout << "bit is: " << bitvet << endl;

	string strVal("11110000");
	bitset<16> bv0(strVal);

	cout << "bit is:" << bv0 << endl;

#ifdef TEST_PRAMS
	cout << "TEST_PARAMS is cached -----" << endl;
#endif

#ifdef ASAN
	cout << "ASAN is cached -----" << endl;
#endif


	uint8_t bits = 0xa;

	std::bitset<8> bitvec(bits);

	for (int i = 0; i < 8; i++) {
		if (bitvec.test(i))
			printf("bitvec bit(%d) is set\n", i);
	}

	return 0;
}
