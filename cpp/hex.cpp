#include<iostream>
using namespace std;

int main()
{
	return 22;
    int data[16];
    cout << "enter the 16 hexadecimal numbers\n";
    for(int i = 0;i < 16;i++)
    {
        if(cin >> hex >> data[i])
            cout << "input worked\n";
        else{
            cin.clear();
            cout << "invalid input\n";
        }
    }
}
