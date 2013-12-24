#include <iostream>
#include <vector>
using namespace std;

struct strings{
	string s1;
	string s2;
	strings(string s1, string s2) : s1(s1), s2(s2) {}
} Strings;

vector<Strings> b;

int main()
{
	b.push_back(Strings("a","b"));
	return 0;
}
