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

std::string s0("x");
int main(void)
{
	std::string s("aaaa bbbb cccc dddd");
	//std::cin >> s >> s0;
	//while (getline(cin, line))
			//cout <<  line << endl;
	//std::cout << s << " is your input!" << std::endl;
	//std::cout << s0 << " is your input!" << std::endl;
	cout << "size of string is:" << s.size() << endl;
	cout << "size of s0 is:" << s0.size() << endl;

	string s1, s2 = "The string of s2";
	s1 = s2;
	cout << "s1 = " << s1 << " s2 = " << s2 << endl;

	vector<int> v1;


	//int val;
	//for (int i = 0; i < 10; i++) {
	//	cin >> val;
	//	v1.push_back(val);
	//}	

	//cout << "Value list is: " << endl;
	//for (int i = 0; i < 10; i++) {
	//	cout << v1[i] << endl;
	//}

	bitset<64> bitvet(0xff00ff0ffff);

	cout << "bit is: " << bitvet << endl;

	string strVal("11110000");
	bitset<16> bv0(strVal);

	cout << "bit is:" << bv0 << endl;

	return 0;
}
