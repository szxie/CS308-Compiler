#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	string s ="0xA";
	cout << strtol(s.c_str(), NULL, 16) << endl;
	
	return 0;
}
